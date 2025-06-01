#include "structures.fxh"
#include "particles.fxh"

cbuffer Constants
{
    GlobalConstants g_Constants;
};

#ifndef THREAD_GROUP_SIZE
#   define THREAD_GROUP_SIZE 64
#endif

RWStructuredBuffer<ParticleAttribs> g_Particles;

// Metal backend has a limitation that structured buffers must have
// different element types. So we use a struct to wrap the particle index.
struct HeadData
{
    int FirstParticleIdx;
};
RWStructuredBuffer<HeadData> g_ParticleListHead;

RWStructuredBuffer<int> g_ParticleLists;

[numthreads(THREAD_GROUP_SIZE, 1, 1)]
void main(uint3 Gid  : SV_GroupID,
          uint3 GTid : SV_GroupThreadID)
{
    uint uiGlobalThreadIdx = Gid.x * uint(THREAD_GROUP_SIZE) + GTid.x;
    if (uiGlobalThreadIdx >= g_Constants.uiNumParticles)
        return;

    int iParticleIdx = int(uiGlobalThreadIdx);

    ParticleAttribs Particle = g_Particles[iParticleIdx];
    Particle.f2Pos   = Particle.f2NewPos;
    Particle.f2Speed = Particle.f2NewSpeed;
    Particle.f2Pos  += Particle.f2Speed * g_Constants.f2Scale * g_Constants.fDeltaTime;
    Particle.fTemperature -= Particle.fTemperature * min(g_Constants.fDeltaTime * 2.0, 1.0);

    ClampParticlePosition(Particle.f2Pos, Particle.f2Speed, Particle.fSize, g_Constants.f2Scale);

    /*








    // ---  SintesisCondensacion  (detectar presencia de reactivos--------------------------------------------------------- ---

    if (Particle.iType == 1)
    {
        int2 i2GridPos = GetGridLocation(Particle.f2Pos, g_Constants.i2ParticleGridSize).xy;
        int GridWidth  = g_Constants.i2ParticleGridSize.x;
        int GridHeight = g_Constants.i2ParticleGridSize.y;

        int nearbyReactivo2 = 0;
        float2 attraction = float2(0.0, 0.0);

        for (int y = max(i2GridPos.y - 1, 0); y <= min(i2GridPos.y + 1, GridHeight - 1); ++y)
        {
            for (int x = max(i2GridPos.x - 1, 0); x <= min(i2GridPos.x + 1, GridWidth - 1); ++x)
            {
                int AnotherIdx = g_ParticleListHead[x + y * GridWidth].FirstParticleIdx;
                while (AnotherIdx >= 0)
                {
                    if (iParticleIdx != AnotherIdx)
                    {
                        ParticleAttribs Other = g_Particles[AnotherIdx];
                        if (Other.iType == 2)
                        {
                            float2 dir = normalize(Other.f2Pos - Particle.f2Pos);
                            attraction += dir;
                            nearbyReactivo2++;
                        }
                    }
                    AnotherIdx = g_ParticleLists[AnotherIdx];
                }
            }
        }

        if (nearbyReactivo2 >= 3)
        {
            Particle.f2Speed += normalize(attraction) * 0.02;
            Particle.fTemperature += 0.05;
        }
    }

    // ------------------------------------------------------------------------------------  PolimerizacionRadicalica ---

    if (Particle.iType == 2 && Particle.fTemperature > 0.5)
    {
        Particle.f4Color = float4(1.0, 0.6, 0.2, 1.0); 
        Particle.fSize += 0.01;
    }

    // -------------------------------------------------------------------------------------  EnsambleMolecular ---
    float2 nucleationCenter = float2(0.5, 0.5); 
    if (Particle.iType == 1 || Particle.iType == 2)
    {
        float2 toCenter = normalize(nucleationCenter - Particle.f2Pos);
        Particle.f2Speed += toCenter * 0.01 * g_Constants.fDeltaTime;
    }




    */

    g_Particles[iParticleIdx] = Particle;

    // Bin particles
    int GridIdx = GetGridLocation(Particle.f2Pos, g_Constants.i2ParticleGridSize).z;
    int OriginalListIdx;
    InterlockedExchange(g_ParticleListHead[GridIdx].FirstParticleIdx, iParticleIdx, OriginalListIdx);
    g_ParticleLists[iParticleIdx] = OriginalListIdx;
}
