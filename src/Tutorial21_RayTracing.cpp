#include "Tutorial21_RayTracing.hpp"
#include "MapHelper.hpp"
#include "GraphicsTypesX.hpp"
#include "GraphicsUtilities.h"
#include "TextureUtilities.h"
#include "ShaderMacroHelper.hpp"
#include "imgui.h"
#include "ImGuiUtils.hpp"
#include "AdvancedMath.hpp"
#include "PlatformMisc.hpp"

#include <random>
namespace Diligent
{
float numSpheres = 0.0f;
float numCubes   = 0.0f;
bool  reaccion   = true;

float s1x = -37.5f, s1z = 17.3f, s2x = -4.2f, s2z = -26.8f, s3x = 28.2f, s3z = -15.2f, s4x = 6.7f, s4z = 39.3f, s5x = -26.3f, s5z = 41.3f;
float s6x = -41.3f, s6z = -4.8f, s7x = 17.2f, s7z = -37.2f, s8x = -11.7f, s8z = 26.5f, s9x = -7.7f, s9z = 34.7f, s10x = -34.2f, s10z = 13.2f;
float s11x = 43.2f, s11z = -22.3f, s12x = 1.3f, s12z = -40.7f, s13x = -13.3f, s13z = 22.5f, s14x = -29.2f, s14z = -1.7f, s15x = 9.3f, s15z = -46.3f;
float s16x = 31.2f, s16z = -12.2f, s17x = -35.7f, s17z = 18.8f, s18x = -6.3f, s18z = 45.2f, s19x = 25.7f, s19z = -20.7f, s20x = -43.8f, s20z = 12.8f;
float s21x = -17.2f, s21z = 38.3f, s22x = 4.5f, s22z = -32.8f, s23x = 21.7f, s23z = -8.7f, s24x = -26.2f, s24z = 29.3f, s25x = -40.3f, s25z = 8.2f;
float s26x = 34.8f, s26z = -16.5f, s27x = -2.8f, s27z = -36.3f, s28x = 19.3f, s28z = 41.7f, s29x = -21.7f, s29z = 26.2f, s30x = 0.7f, s30z = -45.2f;
float s31x = 8.7f, s31z = -30.5f, s32x = -13.0f, s32z = 36.8f, s33x = 24.3f, s33z = -5.0f, s34x = 15.2f, s34z = 19.0f, s35x = -6.7f, s35z = -42.8f;
float s36x = 0.0f, s36z = 0.0f, s37x = 3.8f, s37z = -24.3f, s38x = -27.0f, s38z = 14.8f, s39x = 11.2f, s39z = -16.5f, s40x = -19.2f, s40z = 43.8f;
float s41x = 22.0f, s41z = -20.7f, s42x = -15.0f, s42z = 7.7f, s43x = 6.5f, s43z = -12.8f, s44x = 16.8f, s44z = 22.2f, s45x = -4.7f, s45z = 30.8f;
float s46x = 12.3f, s46z = -33.3f, s47x = -10.0f, s47z = -16.8f, s48x = 26.5f, s48z = 8.3f, s49x = 2.5f, s49z = -37.2f, s50x = -14.7f, s50z = 21.2f;
float s51x = 20.5f, s51z = -28.0f, s52x = 7.3f, s52z = 15.2f, s53x = -17.8f, s53z = -7.3f, s54x = 10.2f, s54z = 31.7f, s55x = -2.2f, s55z = -14.2f;
float s56x = 19.5f, s56z = 10.5f, s57x = -9.2f, s57z = -24.8f, s58x = 13.7f, s58z = 5.8f, s59x = -20.2f, s59z = -3.3f, s60x = 1.5f, s60z = 35.3f;
float s61x = 15.5f, s61z = -29.3f, s62x = -5.2f, s62z = 18.0f, s63x = 13.0f, s63z = -11.5f, s64x = -25.5f, s64z = 23.7f, s65x = 5.3f, s65z = -18.8f;
float s66x = -11.2f, s66z = 3.2f, s67x = 9.3f, s67z = -40.7f, s68x = -24.2f, s68z = 26.7f, s69x = 3.3f, s69z = -8.7f, s70x = 17.8f, s70z = 12.7f;
float s71x = -12.0f, s71z = -23.0f, s72x = 23.2f, s72z = 6.8f, s73x = -4.2f, s73z = -32.7f, s74x = 11.5f, s74z = 25.2f, s75x = -19.7f, s75z = -5.5f;
float s76x = 1.8f, s76z = 20.8f, s77x = -16.2f, s77z = -11.8f, s78x = 7.5f, s78z = 38.8f, s79x = -1.0f, s79z = -27.0f, s80x = 20.0f, s80z = 14.3f;
float s81x = -7.3f, s81z = -36.5f, s82x = 23.8f, s82z = 4.3f, s83x = -13.8f, s83z = -15.8f, s84x = 6.0f, s84z = 23.2f, s85x = -22.7f, s85z = -0.2f;
float s86x = 8.3f, s86z = 29.5f, s87x = -10.3f, s87z = -21.0f, s88x = 18.7f, s88z = 0.5f, s89x = -1.7f, s89z = -39.0f, s90x = 14.5f, s90z = 16.2f;
float s91x = -17.0f, s91z = -9.8f, s92x = 4.7f, s92z = 34.0f, s93x = -13.2f, s93z = -25.0f, s94x = 16.0f, s94z = 5.2f, s95x = -9.7f, s95z = -17.7f;
float s96x = 0.3f, s96z = 30.2f, s97x = -20.8f, s97z = -4.8f, s98x = 10.5f, s98z = 11.3f, s99x = 13.8f, s99z = -9.7f, s100x = 15.2f, s100z = -11.3f;

// Variables c (coordenadas centrales)
float c1x = 26.7f;
float c1z = 30.0f;
float c2x = -7.8f, c2z = 15.5f, c3x = 19.3f, c3z = -20.3f, c4x = -15.2f, c4z = -17.5f, c5x = 11.2f, c5z = 26.3f, c6x = -5.7f, c6z = -11.8f;
float c7x = 3.7f, c7z = 17.2f, c8x = -18.8f, c8z = -24.3f, c9x = 12.5f, c9z = 4.8f, c10x = 6.0f, c10z = -5.7f, c11x = -10.8f, c11z = 10.3f;
float c12x = 2.8f, c12z = 19.0f, c13x = -13.3f, c13z = -15.8f, c14x = 17.0f, c14z = 9.3f, c15x = -30.2f, c15z = 5.5f, c16x = 8.2f, c16z = -3.0f;
float c17x = -18.0f, c17z = -17.3f, c18x = 10.2f, c18z = 24.5f, c19x = -3.8f, c19z = 14.7f, c20x = 0.8f, c20z = -11.5f, c21x = 15.7f, c21z = 0.5f;
float c22x = -9.5f, c22z = -18.8f, c23x = 5.2f, c23z = 21.0f, c24x = -12.0f, c24z = -13.5f, c25x = 14.8f, c25z = 6.7f, c26x = -5.0f, c26z = 12.5f;
float c27x = 2.0f, c27z = -9.0f, c28x = -16.0f, c28z = -3.3f, c29x = 18.3f, c29z = 21.8f, c30x = -6.8f, c30z = 17.8f, c31x = 4.3f, c31z = -15.0f;
float c32x = -11.5f, c32z = -22.5f, c33x = 13.0f, c33z = 5.7f, c34x = -1.3f, c34z = 11.5f, c35x = 10.0f, c35z = -3.8f, c36x = -18.7f, c36z = -13.0f;
float c37x = 7.2f, c37z = 27.5f, c38x = -4.3f, c38z = 16.5f, c39x = 0.0f, c39z = -7.0f, c40x = 17.8f, c40z = 1.8f, c41x = -12.5f, c41z = -16.8f;
float c42x = 6.3f, c42z = 23.0f, c43x = -8.5f, c43z = -10.0f, c44x = 15.0f, c44z = 3.7f, c45x = -2.3f, c45z = 9.5f, c46x = 4.8f, c46z = -6.3f;
float c47x = -16.7f, c47z = -2.0f, c48x = 9.0f, c48z = 25.2f, c49x = -6.2f, c49z = 14.0f, c50x = 1.5f, c50z = -12.7f, c51x = 14.2f, c51z = -0.8f;


SampleBase* CreateSample()
{
    return new Tutorial21_RayTracing();
}


void Tutorial21_RayTracing::CreateGraphicsPSO()
{

    // Create graphics pipeline to blit render target into swapchain image.

    GraphicsPipelineStateCreateInfo PSOCreateInfo;

    PSOCreateInfo.PSODesc.Name         = "Image blit PSO";
    PSOCreateInfo.PSODesc.PipelineType = PIPELINE_TYPE_GRAPHICS;

    PSOCreateInfo.GraphicsPipeline.NumRenderTargets             = 1;
    PSOCreateInfo.GraphicsPipeline.RTVFormats[0]                = m_pSwapChain->GetDesc().ColorBufferFormat;
    PSOCreateInfo.GraphicsPipeline.PrimitiveTopology            = PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
    PSOCreateInfo.GraphicsPipeline.RasterizerDesc.CullMode      = CULL_MODE_NONE;
    PSOCreateInfo.GraphicsPipeline.DepthStencilDesc.DepthEnable = False;

    ShaderCreateInfo ShaderCI;
    ShaderCI.SourceLanguage = SHADER_SOURCE_LANGUAGE_HLSL;
    ShaderCI.ShaderCompiler = SHADER_COMPILER_DXC;
    ShaderCI.CompileFlags   = SHADER_COMPILE_FLAG_PACK_MATRIX_ROW_MAJOR;

    // Create a shader source stream factory to load shaders from files.
    RefCntAutoPtr<IShaderSourceInputStreamFactory> pShaderSourceFactory;
    m_pEngineFactory->CreateDefaultShaderSourceStreamFactory(nullptr, &pShaderSourceFactory);
    ShaderCI.pShaderSourceStreamFactory = pShaderSourceFactory;

    RefCntAutoPtr<IShader> pVS;
    {
        ShaderCI.Desc.ShaderType = SHADER_TYPE_VERTEX;
        ShaderCI.EntryPoint      = "main";
        ShaderCI.Desc.Name       = "Image blit VS";
        ShaderCI.FilePath        = "ImageBlit.vsh";
        m_pDevice->CreateShader(ShaderCI, &pVS);
        VERIFY_EXPR(pVS != nullptr);
    }

    RefCntAutoPtr<IShader> pPS;
    {
        ShaderCI.Desc.ShaderType = SHADER_TYPE_PIXEL;
        ShaderCI.EntryPoint      = "main";
        ShaderCI.Desc.Name       = "Image blit PS";
        ShaderCI.FilePath        = "ImageBlit.psh";
        m_pDevice->CreateShader(ShaderCI, &pPS);
        VERIFY_EXPR(pPS != nullptr);
    }

    PSOCreateInfo.pVS = pVS;
    PSOCreateInfo.pPS = pPS;

    PSOCreateInfo.PSODesc.ResourceLayout.DefaultVariableType = SHADER_RESOURCE_VARIABLE_TYPE_DYNAMIC;

    m_pDevice->CreateGraphicsPipelineState(PSOCreateInfo, &m_pImageBlitPSO);
    VERIFY_EXPR(m_pImageBlitPSO != nullptr);

    m_pImageBlitPSO->CreateShaderResourceBinding(&m_pImageBlitSRB, true);
    VERIFY_EXPR(m_pImageBlitSRB != nullptr);
}

void Tutorial21_RayTracing::CreateRayTracingPSO()
{
    m_MaxRecursionDepth = std::min(m_MaxRecursionDepth, m_pDevice->GetAdapterInfo().RayTracing.MaxRecursionDepth);

    // Prepare ray tracing pipeline description.
    RayTracingPipelineStateCreateInfoX PSOCreateInfo;

    PSOCreateInfo.PSODesc.Name         = "Ray tracing PSO";
    PSOCreateInfo.PSODesc.PipelineType = PIPELINE_TYPE_RAY_TRACING;

    // Define shader macros
    ShaderMacroHelper Macros;
    Macros.AddShaderMacro("NUM_TEXTURES", NumTextures);

    ShaderCreateInfo ShaderCI;
    // We will not be using combined texture samplers as they
    // are only required for compatibility with OpenGL, and ray
    // tracing is not supported in OpenGL backend.
    ShaderCI.Desc.UseCombinedTextureSamplers = false;

    ShaderCI.Macros = Macros;

    // Only new DXC compiler can compile HLSL ray tracing shaders.
    ShaderCI.ShaderCompiler = SHADER_COMPILER_DXC;

    // Use row-major matrices.
    ShaderCI.CompileFlags = SHADER_COMPILE_FLAG_PACK_MATRIX_ROW_MAJOR;

    // Shader model 6.3 is required for DXR 1.0, shader model 6.5 is required for DXR 1.1 and enables additional features.
    // Use 6.3 for compatibility with DXR 1.0 and VK_NV_ray_tracing.
    ShaderCI.HLSLVersion    = {6, 3};
    ShaderCI.SourceLanguage = SHADER_SOURCE_LANGUAGE_HLSL;

    // Create a shader source stream factory to load shaders from files.
    RefCntAutoPtr<IShaderSourceInputStreamFactory> pShaderSourceFactory;
    m_pEngineFactory->CreateDefaultShaderSourceStreamFactory(nullptr, &pShaderSourceFactory);
    ShaderCI.pShaderSourceStreamFactory = pShaderSourceFactory;

    // Create ray generation shader.
    RefCntAutoPtr<IShader> pRayGen;
    {
        ShaderCI.Desc.ShaderType = SHADER_TYPE_RAY_GEN;
        ShaderCI.Desc.Name       = "Ray tracing RG";
        ShaderCI.FilePath        = "RayTrace.rgen";
        ShaderCI.EntryPoint      = "main";
        m_pDevice->CreateShader(ShaderCI, &pRayGen);
        VERIFY_EXPR(pRayGen != nullptr);
    }

    // Create miss shaders.
    RefCntAutoPtr<IShader> pPrimaryMiss, pShadowMiss;
    {
        ShaderCI.Desc.ShaderType = SHADER_TYPE_RAY_MISS;
        ShaderCI.Desc.Name       = "Primary ray miss shader";
        ShaderCI.FilePath        = "PrimaryMiss.rmiss";
        ShaderCI.EntryPoint      = "main";
        m_pDevice->CreateShader(ShaderCI, &pPrimaryMiss);
        VERIFY_EXPR(pPrimaryMiss != nullptr);

        ShaderCI.Desc.Name  = "Shadow ray miss shader";
        ShaderCI.FilePath   = "ShadowMiss.rmiss";
        ShaderCI.EntryPoint = "main";
        m_pDevice->CreateShader(ShaderCI, &pShadowMiss);
        VERIFY_EXPR(pShadowMiss != nullptr);
    }

    // Create closest hit shaders.
    RefCntAutoPtr<IShader> pCubePrimaryHit, pGroundHit, pGlassPrimaryHit, pSpherePrimaryHit;
    {
        ShaderCI.Desc.ShaderType = SHADER_TYPE_RAY_CLOSEST_HIT;
        ShaderCI.Desc.Name       = "Cube primary ray closest hit shader";
        ShaderCI.FilePath        = "CubePrimaryHit.rchit";
        ShaderCI.EntryPoint      = "main";
        m_pDevice->CreateShader(ShaderCI, &pCubePrimaryHit);
        VERIFY_EXPR(pCubePrimaryHit != nullptr);

        ShaderCI.Desc.Name  = "Ground primary ray closest hit shader";
        ShaderCI.FilePath   = "Ground.rchit";
        ShaderCI.EntryPoint = "main";
        m_pDevice->CreateShader(ShaderCI, &pGroundHit);
        VERIFY_EXPR(pGroundHit != nullptr);

        ShaderCI.Desc.Name  = "Glass primary ray closest hit shader";
        ShaderCI.FilePath   = "GlassPrimaryHit.rchit";
        ShaderCI.EntryPoint = "main";
        m_pDevice->CreateShader(ShaderCI, &pGlassPrimaryHit);
        VERIFY_EXPR(pGlassPrimaryHit != nullptr);

        ShaderCI.Desc.Name  = "Sphere primary ray closest hit shader";
        ShaderCI.FilePath   = "SpherePrimaryHit.rchit";
        ShaderCI.EntryPoint = "main";
        m_pDevice->CreateShader(ShaderCI, &pSpherePrimaryHit);
        VERIFY_EXPR(pSpherePrimaryHit != nullptr);
    }

    // Create intersection shader for a procedural sphere.
    RefCntAutoPtr<IShader> pSphereIntersection;
    {
        ShaderCI.Desc.ShaderType = SHADER_TYPE_RAY_INTERSECTION;
        ShaderCI.Desc.Name       = "Sphere intersection shader";
        ShaderCI.FilePath        = "SphereIntersection.rint";
        ShaderCI.EntryPoint      = "main";
        m_pDevice->CreateShader(ShaderCI, &pSphereIntersection);
        VERIFY_EXPR(pSphereIntersection != nullptr);
    }

    // Setup shader groups

    // Ray generation shader is an entry point for a ray tracing pipeline.
    PSOCreateInfo.AddGeneralShader("Main", pRayGen);
    // Primary ray miss shader.
    PSOCreateInfo.AddGeneralShader("PrimaryMiss", pPrimaryMiss);
    // Shadow ray miss shader.
    PSOCreateInfo.AddGeneralShader("ShadowMiss", pShadowMiss);

    // Primary ray hit group for the textured cube.
    PSOCreateInfo.AddTriangleHitShader("CubePrimaryHit", pCubePrimaryHit);
    // Primary ray hit group for the ground.
    PSOCreateInfo.AddTriangleHitShader("GroundHit", pGroundHit);
    // Primary ray hit group for the glass cube.
    PSOCreateInfo.AddTriangleHitShader("GlassPrimaryHit", pGlassPrimaryHit);

    // Intersection and closest hit shaders for the procedural sphere.
    PSOCreateInfo.AddProceduralHitShader("SpherePrimaryHit", pSphereIntersection, pSpherePrimaryHit);
    // Only intersection shader is needed for shadows.
    PSOCreateInfo.AddProceduralHitShader("SphereShadowHit", pSphereIntersection);

    // Specify the maximum ray recursion depth.
    // WARNING: the driver does not track the recursion depth and it is the
    //          application's responsibility to not exceed the specified limit.
    //          The value is used to reserve the necessary stack size and
    //          exceeding it will likely result in driver crash.
    PSOCreateInfo.RayTracingPipeline.MaxRecursionDepth = static_cast<Uint8>(m_MaxRecursionDepth);

    // Per-shader data is not used.
    PSOCreateInfo.RayTracingPipeline.ShaderRecordSize = 0;

    // DirectX 12 only: set attribute and payload size. Values should be as small as possible to minimize the memory usage.
    PSOCreateInfo.MaxAttributeSize = std::max<Uint32>(sizeof(/* BuiltInTriangleIntersectionAttributes */ float2), sizeof(HLSL::ProceduralGeomIntersectionAttribs));
    PSOCreateInfo.MaxPayloadSize   = std::max<Uint32>(sizeof(HLSL::PrimaryRayPayload), sizeof(HLSL::ShadowRayPayload));

    // Define immutable sampler for g_Texture and g_GroundTexture. Immutable samplers should be used whenever possible
    SamplerDesc SamLinearWrapDesc{
        FILTER_TYPE_LINEAR, FILTER_TYPE_LINEAR, FILTER_TYPE_LINEAR,
        TEXTURE_ADDRESS_WRAP, TEXTURE_ADDRESS_WRAP, TEXTURE_ADDRESS_WRAP //
    };

    PipelineResourceLayoutDescX ResourceLayout;
    ResourceLayout.DefaultVariableType = SHADER_RESOURCE_VARIABLE_TYPE_MUTABLE;
    ResourceLayout.AddImmutableSampler(SHADER_TYPE_RAY_CLOSEST_HIT, "g_SamLinearWrap", SamLinearWrapDesc);
    ResourceLayout
        .AddVariable(SHADER_TYPE_RAY_GEN | SHADER_TYPE_RAY_MISS | SHADER_TYPE_RAY_CLOSEST_HIT, "g_ConstantsCB", SHADER_RESOURCE_VARIABLE_TYPE_STATIC)
        .AddVariable(SHADER_TYPE_RAY_GEN, "g_ColorBuffer", SHADER_RESOURCE_VARIABLE_TYPE_DYNAMIC);

    PSOCreateInfo.PSODesc.ResourceLayout = ResourceLayout;

    m_pDevice->CreateRayTracingPipelineState(PSOCreateInfo, &m_pRayTracingPSO);
    VERIFY_EXPR(m_pRayTracingPSO != nullptr);

    m_pRayTracingPSO->GetStaticVariableByName(SHADER_TYPE_RAY_GEN, "g_ConstantsCB")->Set(m_ConstantsCB);
    m_pRayTracingPSO->GetStaticVariableByName(SHADER_TYPE_RAY_MISS, "g_ConstantsCB")->Set(m_ConstantsCB);
    m_pRayTracingPSO->GetStaticVariableByName(SHADER_TYPE_RAY_CLOSEST_HIT, "g_ConstantsCB")->Set(m_ConstantsCB);

    m_pRayTracingPSO->CreateShaderResourceBinding(&m_pRayTracingSRB, true);
    VERIFY_EXPR(m_pRayTracingSRB != nullptr);
}

void Tutorial21_RayTracing::LoadTextures()
{
    // Load textures
    IDeviceObject*          pTexSRVs[NumTextures] = {};
    RefCntAutoPtr<ITexture> pTex[NumTextures];
    StateTransitionDesc     Barriers[NumTextures];
    for (int tex = 0; tex < NumTextures; ++tex)
    {
        // Load current texture
        TextureLoadInfo loadInfo;
        loadInfo.IsSRGB = true;

        std::stringstream FileNameSS;
        FileNameSS << "DGLogo" << tex << ".png";
        auto FileName = FileNameSS.str();
        CreateTextureFromFile(FileName.c_str(), loadInfo, m_pDevice, &pTex[tex]);

        // Get shader resource view from the texture
        auto* pTextureSRV = pTex[tex]->GetDefaultView(TEXTURE_VIEW_SHADER_RESOURCE);
        pTexSRVs[tex]     = pTextureSRV;
        Barriers[tex]     = StateTransitionDesc{pTex[tex], RESOURCE_STATE_UNKNOWN, RESOURCE_STATE_SHADER_RESOURCE, STATE_TRANSITION_FLAG_UPDATE_STATE};
    }
    m_pImmediateContext->TransitionResourceStates(_countof(Barriers), Barriers);

    m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_CLOSEST_HIT, "g_CubeTextures")->SetArray(pTexSRVs, 0, NumTextures);

    // Load ground texture
    RefCntAutoPtr<ITexture> pGroundTex;
    CreateTextureFromFile("Ground.jpg", TextureLoadInfo{}, m_pDevice, &pGroundTex);

    m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_CLOSEST_HIT, "g_GroundTexture")->Set(pGroundTex->GetDefaultView(TEXTURE_VIEW_SHADER_RESOURCE));
}

void Tutorial21_RayTracing::CreateCubeBLAS()
{
    RefCntAutoPtr<IDataBlob> pCubeVerts;
    RefCntAutoPtr<IDataBlob> pCubeIndices;
    GeometryPrimitiveInfo    CubeGeoInfo;
    constexpr float          CubeSize = 2.f;
    CreateGeometryPrimitive(CubeGeometryPrimitiveAttributes{CubeSize, GEOMETRY_PRIMITIVE_VERTEX_FLAG_ALL}, &pCubeVerts, &pCubeIndices, &CubeGeoInfo);

    struct CubeVertex
    {
        float3 Pos;
        float3 Normal;
        float2 UV;
    };
    VERIFY_EXPR(CubeGeoInfo.VertexSize == sizeof(CubeVertex));
    const CubeVertex* pVerts   = pCubeVerts->GetConstDataPtr<CubeVertex>();
    const Uint32*     pIndices = pCubeIndices->GetConstDataPtr<Uint32>();

    // Create a buffer with cube attributes.
    // These attributes will be used in the hit shader to calculate UVs and normal for intersection point.
    {
        HLSL::CubeAttribs Attribs;
        for (Uint32 v = 0; v < CubeGeoInfo.NumVertices; ++v)
        {
            Attribs.UVs[v]     = {pVerts[v].UV, 0, 0};
            Attribs.Normals[v] = pVerts[v].Normal;
        }

        for (Uint32 i = 0; i < CubeGeoInfo.NumIndices; i += 3)
        {
            const Uint32* TriIdx{&pIndices[i]};
            Attribs.Primitives[i / 3] = uint4{TriIdx[0], TriIdx[1], TriIdx[2], 0};
        }

        BufferDesc BuffDesc;
        BuffDesc.Name      = "Cube Attribs";
        BuffDesc.Usage     = USAGE_IMMUTABLE;
        BuffDesc.BindFlags = BIND_UNIFORM_BUFFER;
        BuffDesc.Size      = sizeof(Attribs);

        BufferData BufData = {&Attribs, BuffDesc.Size};

        m_pDevice->CreateBuffer(BuffDesc, &BufData, &m_CubeAttribsCB);
        VERIFY_EXPR(m_CubeAttribsCB != nullptr);

        m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_CLOSEST_HIT, "g_CubeAttribsCB")->Set(m_CubeAttribsCB);
    }

    // Create vertex and index buffers
    RefCntAutoPtr<IBuffer>             pCubeVertexBuffer;
    RefCntAutoPtr<IBuffer>             pCubeIndexBuffer;
    GeometryPrimitiveBuffersCreateInfo CubeBuffersCI;
    CubeBuffersCI.VertexBufferBindFlags = BIND_RAY_TRACING;
    CubeBuffersCI.IndexBufferBindFlags  = BIND_RAY_TRACING;
    CreateGeometryPrimitiveBuffers(m_pDevice, CubeGeometryPrimitiveAttributes{CubeSize, GEOMETRY_PRIMITIVE_VERTEX_FLAG_POSITION},
                                   &CubeBuffersCI, &pCubeVertexBuffer, &pCubeIndexBuffer);

    // Create & build bottom level acceleration structure
    {
        // Create BLAS
        BLASTriangleDesc Triangles;
        {
            Triangles.GeometryName         = "Cube";
            Triangles.MaxVertexCount       = CubeGeoInfo.NumVertices;
            Triangles.VertexValueType      = VT_FLOAT32;
            Triangles.VertexComponentCount = 3;
            Triangles.MaxPrimitiveCount    = CubeGeoInfo.NumIndices / 3;
            Triangles.IndexType            = VT_UINT32;

            BottomLevelASDesc ASDesc;
            ASDesc.Name          = "Cube BLAS";
            ASDesc.Flags         = RAYTRACING_BUILD_AS_PREFER_FAST_TRACE;
            ASDesc.pTriangles    = &Triangles;
            ASDesc.TriangleCount = 1;

            m_pDevice->CreateBLAS(ASDesc, &m_pCubeBLAS);
            VERIFY_EXPR(m_pCubeBLAS != nullptr);
        }

        // Create scratch buffer
        RefCntAutoPtr<IBuffer> pScratchBuffer;
        {
            BufferDesc BuffDesc;
            BuffDesc.Name      = "BLAS Scratch Buffer";
            BuffDesc.Usage     = USAGE_DEFAULT;
            BuffDesc.BindFlags = BIND_RAY_TRACING;
            BuffDesc.Size      = m_pCubeBLAS->GetScratchBufferSizes().Build;

            m_pDevice->CreateBuffer(BuffDesc, nullptr, &pScratchBuffer);
            VERIFY_EXPR(pScratchBuffer != nullptr);
        }

        // Build BLAS
        BLASBuildTriangleData TriangleData;
        TriangleData.GeometryName         = Triangles.GeometryName;
        TriangleData.pVertexBuffer        = pCubeVertexBuffer;
        TriangleData.VertexStride         = sizeof(float3);
        TriangleData.VertexCount          = Triangles.MaxVertexCount;
        TriangleData.VertexValueType      = Triangles.VertexValueType;
        TriangleData.VertexComponentCount = Triangles.VertexComponentCount;
        TriangleData.pIndexBuffer         = pCubeIndexBuffer;
        TriangleData.PrimitiveCount       = Triangles.MaxPrimitiveCount;
        TriangleData.IndexType            = Triangles.IndexType;
        TriangleData.Flags                = RAYTRACING_GEOMETRY_FLAG_OPAQUE;

        BuildBLASAttribs Attribs;
        Attribs.pBLAS             = m_pCubeBLAS;
        Attribs.pTriangleData     = &TriangleData;
        Attribs.TriangleDataCount = 1;

        // Scratch buffer will be used to store temporary data during BLAS build.
        // Previous content in the scratch buffer will be discarded.
        Attribs.pScratchBuffer = pScratchBuffer;

        // Allow engine to change resource states.
        Attribs.BLASTransitionMode          = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
        Attribs.GeometryTransitionMode      = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
        Attribs.ScratchBufferTransitionMode = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;

        m_pImmediateContext->BuildBLAS(Attribs);
    }
}

void Tutorial21_RayTracing::CreateProceduralBLAS()
{
    static_assert(sizeof(HLSL::BoxAttribs) % 16 == 0, "BoxAttribs must be aligned by 16 bytes");

    const HLSL::BoxAttribs Boxes[] = {HLSL::BoxAttribs{-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f}};

    // Create box buffer
    {
        BufferData BufData = {Boxes, sizeof(Boxes)};
        BufferDesc BuffDesc;
        BuffDesc.Name              = "AABB Buffer";
        BuffDesc.Usage             = USAGE_IMMUTABLE;
        BuffDesc.BindFlags         = BIND_RAY_TRACING | BIND_SHADER_RESOURCE;
        BuffDesc.Size              = sizeof(Boxes);
        BuffDesc.ElementByteStride = sizeof(Boxes[0]);
        BuffDesc.Mode              = BUFFER_MODE_STRUCTURED;

        m_pDevice->CreateBuffer(BuffDesc, &BufData, &m_BoxAttribsCB);
        VERIFY_EXPR(m_BoxAttribsCB != nullptr);

        m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_INTERSECTION, "g_BoxAttribs")->Set(m_BoxAttribsCB->GetDefaultView(BUFFER_VIEW_SHADER_RESOURCE));
    }

    // Create & build bottom level acceleration structure
    {
        // Create BLAS
        BLASBoundingBoxDesc BoxInfo;
        {
            BoxInfo.GeometryName = "Box";
            BoxInfo.MaxBoxCount  = 1;

            BottomLevelASDesc ASDesc;
            ASDesc.Name     = "Procedural BLAS";
            ASDesc.Flags    = RAYTRACING_BUILD_AS_PREFER_FAST_TRACE;
            ASDesc.pBoxes   = &BoxInfo;
            ASDesc.BoxCount = 1;

            m_pDevice->CreateBLAS(ASDesc, &m_pProceduralBLAS);
            VERIFY_EXPR(m_pProceduralBLAS != nullptr);
        }

        // Create scratch buffer
        RefCntAutoPtr<IBuffer> pScratchBuffer;
        {
            BufferDesc BuffDesc;
            BuffDesc.Name      = "BLAS Scratch Buffer";
            BuffDesc.Usage     = USAGE_DEFAULT;
            BuffDesc.BindFlags = BIND_RAY_TRACING;
            BuffDesc.Size      = m_pProceduralBLAS->GetScratchBufferSizes().Build;

            m_pDevice->CreateBuffer(BuffDesc, nullptr, &pScratchBuffer);
            VERIFY_EXPR(pScratchBuffer != nullptr);
        }

        // Build BLAS
        BLASBuildBoundingBoxData BoxData;
        BoxData.GeometryName = BoxInfo.GeometryName;
        BoxData.BoxCount     = 1;
        BoxData.BoxStride    = sizeof(Boxes[0]);
        BoxData.pBoxBuffer   = m_BoxAttribsCB;

        BuildBLASAttribs Attribs;
        Attribs.pBLAS        = m_pProceduralBLAS;
        Attribs.pBoxData     = &BoxData;
        Attribs.BoxDataCount = 1;

        // Scratch buffer will be used to store temporary data during BLAS build.
        // Previous content in the scratch buffer will be discarded.
        Attribs.pScratchBuffer = pScratchBuffer;

        // Allow engine to change resource states.
        Attribs.BLASTransitionMode          = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
        Attribs.GeometryTransitionMode      = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
        Attribs.ScratchBufferTransitionMode = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;

        m_pImmediateContext->BuildBLAS(Attribs);
    }
}

void Tutorial21_RayTracing::UpdateTLAS()
{
    // Create or update top-level acceleration structure

    static constexpr int NumInstances = NumCubes + 155;

    bool NeedUpdate = true;

    // Create TLAS
    if (!m_pTLAS)
    {
        TopLevelASDesc TLASDesc;
        TLASDesc.Name             = "TLAS";
        TLASDesc.MaxInstanceCount = NumInstances;
        TLASDesc.Flags            = RAYTRACING_BUILD_AS_ALLOW_UPDATE | RAYTRACING_BUILD_AS_PREFER_FAST_TRACE;

        m_pDevice->CreateTLAS(TLASDesc, &m_pTLAS);
        VERIFY_EXPR(m_pTLAS != nullptr);

        NeedUpdate = false; // build on first run

        m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_GEN, "g_TLAS")->Set(m_pTLAS);
        m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_CLOSEST_HIT, "g_TLAS")->Set(m_pTLAS);
    }

    // Create scratch buffer
    if (!m_ScratchBuffer)
    {
        BufferDesc BuffDesc;
        BuffDesc.Name      = "TLAS Scratch Buffer";
        BuffDesc.Usage     = USAGE_DEFAULT;
        BuffDesc.BindFlags = BIND_RAY_TRACING;
        BuffDesc.Size      = std::max(m_pTLAS->GetScratchBufferSizes().Build, m_pTLAS->GetScratchBufferSizes().Update);

        m_pDevice->CreateBuffer(BuffDesc, nullptr, &m_ScratchBuffer);
        VERIFY_EXPR(m_ScratchBuffer != nullptr);
    }

    // Create instance buffer
    if (!m_InstanceBuffer)
    {
        BufferDesc BuffDesc;
        BuffDesc.Name      = "TLAS Instance Buffer";
        BuffDesc.Usage     = USAGE_DEFAULT;
        BuffDesc.BindFlags = BIND_RAY_TRACING;
        BuffDesc.Size      = TLAS_INSTANCE_DATA_SIZE * NumInstances;

        m_pDevice->CreateBuffer(BuffDesc, nullptr, &m_InstanceBuffer);
        VERIFY_EXPR(m_InstanceBuffer != nullptr);
    }

    // Setup instances
    TLASBuildInstanceData Instances[NumInstances] = {};

    struct CubeInstanceData
    {
        float3 BasePos;
        float  TimeOffset;
    } CubeInstData[] = // clang-format off
    {
        {float3{ 1, 1,  1}, 0.00f},
        {float3{ 2, 0, -1}, 0.53f},
        {float3{-1, 1,  2}, 1.27f},
        {float3{-2, 0, -1}, 4.16f}
    };
    // clang-format on
    static_assert(_countof(CubeInstData) == NumCubes, "Cube instance data array size mismatch");

    const auto AnimateOpaqueCube = [&](TLASBuildInstanceData& Dst) //
    {
        float  t     = sin(m_AnimationTime * PI_F * 0.5f) + CubeInstData[Dst.CustomId].TimeOffset;
        float3 Pos   = CubeInstData[Dst.CustomId].BasePos * 2.0f + float3(sin(t * 1.13f), sin(t * 0.77f), sin(t * 2.15f)) * 0.5f;
        float  angle = 0.1f * PI_F * (m_AnimationTime + CubeInstData[Dst.CustomId].TimeOffset * 2.0f);

        if (!m_EnableCubes[Dst.CustomId])
            Dst.Mask = 0;

        Dst.Transform.SetTranslation(Pos.x, -Pos.y, Pos.z);
        Dst.Transform.SetRotation(float3x3::RotationY(angle).Data());
    };

    Instances[0].InstanceName = "Cube Instance 1";
    Instances[0].CustomId     = 0; // texture index
    Instances[0].pBLAS        = m_pCubeBLAS;
    Instances[0].Mask         = OPAQUE_GEOM_MASK;
    Instances[0].Transform.SetTranslation(-8.0f, -400.2f, -20.f);

    Instances[1].InstanceName = "Cube Instance 2";
    Instances[1].CustomId     = 1; // texture index
    Instances[1].pBLAS        = m_pCubeBLAS;
    Instances[1].Mask         = OPAQUE_GEOM_MASK;
    Instances[1].Transform.SetTranslation(-10.0f, -400.2f, -25.0f);

    Instances[2].InstanceName = "Cube Instance 3";
    Instances[2].CustomId     = 2; // texture index
    Instances[2].pBLAS        = m_pCubeBLAS;
    Instances[2].Mask         = OPAQUE_GEOM_MASK;
    Instances[2].Transform.SetTranslation(-12.0f, -400.2f, -14.f);

    Instances[3].InstanceName = "Cube Instance 4";
    Instances[3].CustomId     = 3; // texture index
    Instances[3].pBLAS        = m_pCubeBLAS;
    Instances[3].Mask         = OPAQUE_GEOM_MASK;
    Instances[3].Transform.SetTranslation(-18.0f, -110.2f, -0.f);

    /*
    Instances[134].InstanceName = "Cube Instance 5";
    Instances[134].CustomId     = 3; // texture index
    Instances[134].pBLAS        = m_pCubeBLAS;
    Instances[134].Mask         = OPAQUE_GEOM_MASK;
    Instances[134].Transform.SetTranslation(-12.0f, -4.2f, -0.f);
    */

    Instances[4].InstanceName = "Ground Instance";
    Instances[4].pBLAS        = m_pCubeBLAS;
    Instances[4].Mask         = OPAQUE_GEOM_MASK;
    Instances[4].Transform.SetRotation(float3x3::Scale(100.0f, 0.1f, 100.0f).Data());
    Instances[4].Transform.SetTranslation(0.0f, -5.3f, 0.0f);



    Instances[6].InstanceName = "Glass Instance";
    Instances[6].pBLAS        = m_pCubeBLAS;
    Instances[6].Mask         = TRANSPARENT_GEOM_MASK;
    Instances[6].Transform.SetRotation((float3x3::Scale(1.5f, -2.25f, 1.5f) * float3x3::RotationY(0.0f * 0.0f * 0.25f)).Data());
    Instances[6].Transform.SetTranslation(-2.0f, -40.5f, -28.f);
    /*
    Instances[109].InstanceName = "Glass Instance 2";
    Instances[109].pBLAS        = m_pCubeBLAS;
    Instances[109].Mask           = TRANSPARENT_GEOM_MASK;
    Instances[109].Transform.SetRotation((float3x3::Scale(1.5f, -2.25f, 1.5f) * float3x3::RotationY(0.0f * 0.0f * 0.25f)).Data());
    Instances[109].Transform.SetTranslation(-5.0f, -4.5f, -28.f);
    */
    Instances[5].InstanceName = "Sphere Instance";
    Instances[5].CustomId     = 0; // box index
    Instances[5].pBLAS        = m_pProceduralBLAS;
    Instances[5].Mask         = OPAQUE_GEOM_MASK;
    Instances[5].Transform.SetTranslation(-18.0f, -4.2f, -17.f);

    Instances[7].InstanceName = "Sphere Instance 2";
    Instances[7].CustomId     = 0; // box index
    Instances[7].pBLAS        = m_pProceduralBLAS;
    Instances[7].Mask         = OPAQUE_GEOM_MASK;
    Instances[7].Transform.SetTranslation(-19.0f, -4.2f, -18.f);

    Instances[8].InstanceName = "Sphere Instance 3";
    Instances[8].CustomId     = 0; // box index
    Instances[8].pBLAS        = m_pProceduralBLAS;
    Instances[8].Mask         = OPAQUE_GEOM_MASK;
    Instances[8].Transform.SetTranslation(-19.0f, -4.2f, -16.f);

    //----------------


    //aDITIONAL SPHERES

    std::vector<std::string> instanceNames;
    for (int i = 0; i < 100; ++i)
    {
        int idx = 9 + i;
        instanceNames.emplace_back("Sphere Instance " + std::to_string(i + 4));
        Instances[idx].InstanceName = instanceNames.back().c_str();
        Instances[idx].CustomId     = 0;
        Instances[idx].pBLAS        = m_pProceduralBLAS;
        Instances[idx].Mask         = OPAQUE_GEOM_MASK;

        if (numSpheres > i)
        {
            float x = 0.0f;
            float z = 0.0f;

            float sx[100] = {
                s1x, s2x, s3x, s4x, s5x, s6x, s7x, s8x, s9x, s10x,
                s11x, s12x, s13x, s14x, s15x, s16x, s17x, s18x, s19x, s20x,
                s21x, s22x, s23x, s24x, s25x, s26x, s27x, s28x, s29x, s30x,
                s31x, s32x, s33x, s34x, s35x, s36x, s37x, s38x, s39x, s40x,
                s41x, s42x, s43x, s44x, s45x, s46x, s47x, s48x, s49x, s50x,
                s51x, s52x, s53x, s54x, s55x, s56x, s57x, s58x, s59x, s60x,
                s61x, s62x, s63x, s64x, s65x, s66x, s67x, s68x, s69x, s70x,
                s71x, s72x, s73x, s74x, s75x, s76x, s77x, s78x, s79x, s80x,
                s81x, s82x, s83x, s84x, s85x, s86x, s87x, s88x, s89x, s90x,
                s91x, s92x, s93x, s94x, s95x, s96x, s97x, s98x, s99x, s100x};

            float sz[100] = {
                s1z, s2z, s3z, s4z, s5z, s6z, s7z, s8z, s9z, s10z,
                s11z, s12z, s13z, s14z, s15z, s16z, s17z, s18z, s19z, s20z,
                s21z, s22z, s23z, s24z, s25z, s26z, s27z, s28z, s29z, s30z,
                s31z, s32z, s33z, s34z, s35z, s36z, s37z, s38z, s39z, s40z,
                s41z, s42z, s43z, s44z, s45z, s46z, s47z, s48z, s49z, s50z,
                s51z, s52z, s53z, s54z, s55z, s56z, s57z, s58z, s59z, s60z,
                s61z, s62z, s63z, s64z, s65z, s66z, s67z, s68z, s69z, s70z,
                s71z, s72z, s73z, s74z, s75z, s76z, s77z, s78z, s79z, s80z,
                s81z, s82z, s83z, s84z, s85z, s86z, s87z, s88z, s89z, s90z,
                s91z, s92z, s93z, s94z, s95z, s96z, s97z, s98z, s99z, s100z};


            x = sx[i];
            z = sz[i];


            Instances[idx].Transform.SetTranslation(x, -4.3f, z);
        }
        else
        {
            Instances[idx].Transform.SetTranslation(-30.0f, -30.3f, -10.f);
        }
    }

    std::vector<std::string> instanceNamesCubes;
    for (int i = 0; i < 25; ++i)
    {
        int idx = 109 + i;
        instanceNamesCubes.emplace_back("Glass Instance " + std::to_string(i + 2));
        Instances[idx].InstanceName = instanceNamesCubes.back().c_str();
        Instances[idx].pBLAS        = m_pCubeBLAS;
        Instances[idx].Mask         = TRANSPARENT_GEOM_MASK;


        if (numCubes > i)
        {
            float xC = 0.0f;
            float zC = 0.0f;

            float cx[50] = {
                c1x, c2x, c3x, c4x, c5x, c6x, c7x, c8x, c9x, c10x,
                c11x, c12x, c13x, c14x, c15x, c16x, c17x, c18x, c19x, c20x,
                c21x, c22x, c23x, c24x, c25x, c26x, c27x, c28x, c29x, c30x,
                c31x, c32x, c33x, c34x, c35x, c36x, c37x, c38x, c39x, c40x,
                c41x, c42x, c43x, c44x, c45x, c46x, c47x, c48x, c49x, c50x};

            float cz[50] = {
                c1z, c2z, c3z, c4z, c5z, c6z, c7z, c8z, c9z, c10z,
                c11z, c12z, c13z, c14z, c15z, c16z, c17z, c18z, c19z, c20z,
                c21z, c22z, c23z, c24z, c25z, c26z, c27z, c28z, c29z, c30z,
                c31z, c32z, c33z, c34z, c35z, c36z, c37z, c38z, c39z, c40z,
                c41z, c42z, c43z, c44z, c45z, c46z, c47z, c48z, c49z, c50z};

            // Acceso por índice
            xC = cx[i];
            zC = cz[i];

            Instances[idx].Transform.SetRotation((float3x3::Scale(1.5f, -2.25f, 1.5f) * float3x3::RotationY(0.0f * 0.0f * 0.25f)).Data());
            Instances[idx].Transform.SetTranslation(xC, -4.5f, zC);
        }
        else
        {
            Instances[idx].Transform.SetRotation((float3x3::Scale(-100.5f, -120.25f, 100.5f) * float3x3::RotationY(0.0f * 0.0f * 0.25f)).Data());
            Instances[idx].Transform.SetTranslation(000.0f, -400.5f, 000.0f);
        }
    }


    std::vector<std::string> instanceNamesCubes2;
    for (int i = 0; i < 25; ++i)
    {
        int idx = 134 + i;
        instanceNamesCubes2.emplace_back("Glass Instance " + std::to_string(i + 27));
        Instances[idx].InstanceName = instanceNamesCubes2.back().c_str();
        Instances[idx].CustomId     = 3; // texture index
        Instances[idx].pBLAS        = m_pCubeBLAS;
        Instances[idx].Mask         = OPAQUE_GEOM_MASK;


        if (numCubes > i + 25)
        {
            float xC2 = 0.0f;
            float zC2 = 0.0f;

            float cx[50] = {
                c1x, c2x, c3x, c4x, c5x, c6x, c7x, c8x, c9x, c10x,
                c11x, c12x, c13x, c14x, c15x, c16x, c17x, c18x, c19x, c20x,
                c21x, c22x, c23x, c24x, c25x, c26x, c27x, c28x, c29x, c30x,
                c31x, c32x, c33x, c34x, c35x, c36x, c37x, c38x, c39x, c40x,
                c41x, c42x, c43x, c44x, c45x, c46x, c47x, c48x, c49x, c50x};

            float cz[50] = {
                c1z, c2z, c3z, c4z, c5z, c6z, c7z, c8z, c9z, c10z,
                c11z, c12z, c13z, c14z, c15z, c16z, c17z, c18z, c19z, c20z,
                c21z, c22z, c23z, c24z, c25z, c26z, c27z, c28z, c29z, c30z,
                c31z, c32z, c33z, c34z, c35z, c36z, c37z, c38z, c39z, c40z,
                c41z, c42z, c43z, c44z, c45z, c46z, c47z, c48z, c49z, c50z};

            // Acceso por índice
            xC2 = cx[i + 25];
            zC2 = cz[i + 25];

            Instances[idx].Transform.SetTranslation(xC2, -4.2f, zC2);
        }
        else
        {
            Instances[idx].Transform.SetTranslation(-18.0f, -101.2f, -0.f);
        }
    }
    Instances[9].InstanceName = "Sphere Instance 4";
    Instances[9].CustomId     = 0; // box index
    Instances[9].pBLAS        = m_pProceduralBLAS;
    Instances[9].Mask         = OPAQUE_GEOM_MASK;
    Instances[9].Transform.SetTranslation(-8.0f, -4.2f, -20.f);

    Instances[11].InstanceName = "Sphere Instance 5";
    Instances[11].CustomId     = 0; // box index
    Instances[11].pBLAS        = m_pProceduralBLAS;
    Instances[11].Mask         = OPAQUE_GEOM_MASK;
    Instances[11].Transform.SetTranslation(-9.0f, -4.2f, -21.f);

    Instances[10].InstanceName = "Sphere Instance 6";
    Instances[10].CustomId      = 0; // box index
    Instances[10].pBLAS         = m_pProceduralBLAS;
    Instances[10].Mask          = OPAQUE_GEOM_MASK;
    Instances[10].Transform.SetTranslation(-9.0f, -4.2f, -19.f);

    Instances[12].InstanceName = "Sphere Instance 7";
    Instances[12].CustomId     = 0; // box index
    Instances[12].pBLAS        = m_pProceduralBLAS;
    Instances[12].Mask         = OPAQUE_GEOM_MASK;
    Instances[12].Transform.SetTranslation(-0.0f, -4.2f, -18.f);

    Instances[14].InstanceName = "Sphere Instance 8";
    Instances[14].CustomId     = 0; // box index
    Instances[14].pBLAS        = m_pProceduralBLAS;
    Instances[14].Mask         = OPAQUE_GEOM_MASK;
    Instances[14].Transform.SetTranslation(-1.0f, -4.2f, -19.f);

    Instances[13].InstanceName = "Sphere Instance 9";
    Instances[13].CustomId     = 0; // box index
    Instances[13].pBLAS        = m_pProceduralBLAS;
    Instances[13].Mask         = OPAQUE_GEOM_MASK;
    Instances[13].Transform.SetTranslation(-1.0f, -4.2f, -17.f);

    //-----

    Instances[15].InstanceName = "Sphere Instance 10";
    Instances[15].CustomId     = 0; // box index
    Instances[15].pBLAS        = m_pProceduralBLAS;
    Instances[15].Mask         = OPAQUE_GEOM_MASK;
    Instances[15].Transform.SetTranslation(-6.0f, -4.2f, -1.f);

    Instances[16].InstanceName = "Sphere Instance 11";
    Instances[16].CustomId     = 0; // box index
    Instances[16].pBLAS        = m_pProceduralBLAS;
    Instances[16].Mask         = OPAQUE_GEOM_MASK;
    Instances[16].Transform.SetTranslation(-7.0f, -4.2f, -1.f);

    float yPosition = (reaccion) ? -40.2f : -4.2f;

    //--------------------- res 1
    Instances[17].InstanceName = "Sphere Instance 12";
    Instances[17].CustomId     = 0;
    Instances[17].pBLAS        = m_pProceduralBLAS;
    Instances[17].Mask         = OPAQUE_GEOM_MASK;
    Instances[17].Transform.SetTranslation(-8.0f, yPosition, 10.f);

    Instances[18].InstanceName = "Sphere Instance 13";
    Instances[18].CustomId     = 0;
    Instances[18].pBLAS        = m_pProceduralBLAS;
    Instances[18].Mask         = OPAQUE_GEOM_MASK;
    Instances[18].Transform.SetTranslation(-9.0f, yPosition, 11.0f);

    Instances[19].InstanceName = "Sphere Instance 14";
    Instances[19].CustomId     = 0;
    Instances[19].pBLAS        = m_pProceduralBLAS;
    Instances[19].Mask         = OPAQUE_GEOM_MASK;
    Instances[19].Transform.SetTranslation(-9.0f, yPosition, 9.0f);

    Instances[20].InstanceName = "Sphere Instance 15";
    Instances[20].CustomId     = 0;
    Instances[20].pBLAS        = m_pProceduralBLAS;
    Instances[20].Mask         = OPAQUE_GEOM_MASK;
    Instances[20].Transform.SetTranslation(-7.0f, yPosition, 11.f);

    // resultado 2
    Instances[21].InstanceName = "Sphere Instance 16";
    Instances[21].CustomId     = 0;
    Instances[21].pBLAS        = m_pProceduralBLAS;
    Instances[21].Mask         = OPAQUE_GEOM_MASK;
    Instances[21].Transform.SetTranslation(0.0f, yPosition, 10.0f);

    Instances[22].InstanceName = "Sphere Instance 17";
    Instances[22].CustomId     = 0;
    Instances[22].pBLAS        = m_pProceduralBLAS;
    Instances[22].Mask         = OPAQUE_GEOM_MASK;
    Instances[22].Transform.SetTranslation(-1.0f, yPosition, 11.0f);

    Instances[23].InstanceName = "Sphere Instance 18";
    Instances[23].CustomId     = 0;
    Instances[23].pBLAS        = m_pProceduralBLAS;
    Instances[23].Mask         = OPAQUE_GEOM_MASK;
    Instances[23].Transform.SetTranslation(-1.0f, yPosition, 9.0f);

    Instances[24].InstanceName = "Sphere Instance 19";
    Instances[24].CustomId     = 0;
    Instances[24].pBLAS        = m_pProceduralBLAS;
    Instances[24].Mask         = OPAQUE_GEOM_MASK;
    Instances[24].Transform.SetTranslation(1.0f, yPosition, 11.0f);

    // molécula que queda sola
    Instances[25].InstanceName = "Sphere Instance 20";
    Instances[25].CustomId     = 0;
    Instances[25].pBLAS        = m_pProceduralBLAS;
    Instances[25].Mask         = OPAQUE_GEOM_MASK;
    Instances[25].Transform.SetTranslation(-18.0f, yPosition, 7.0f);

    Instances[26].InstanceName = "Sphere Instance 21";
    Instances[26].CustomId     = 0;
    Instances[26].pBLAS        = m_pProceduralBLAS;
    Instances[26].Mask         = OPAQUE_GEOM_MASK;
    Instances[26].Transform.SetTranslation(-19.0f, yPosition, 8.0f);

    Instances[27].InstanceName = "Sphere Instance 22";
    Instances[27].CustomId     = 0;
    Instances[27].pBLAS        = m_pProceduralBLAS;
    Instances[27].Mask         = OPAQUE_GEOM_MASK;
    Instances[27].Transform.SetTranslation(-19.0f, yPosition, 6.0f);



    // Build or update TLAS
    BuildTLASAttribs Attribs;
    Attribs.pTLAS  = m_pTLAS;
    Attribs.Update = NeedUpdate;

    // Scratch buffer will be used to store temporary data during TLAS build or update.
    // Previous content in the scratch buffer will be discarded.
    Attribs.pScratchBuffer = m_ScratchBuffer;

    // Instance buffer will store instance data during TLAS build or update.
    // Previous content in the instance buffer will be discarded.
    Attribs.pInstanceBuffer = m_InstanceBuffer;

    // Instances will be converted to the format that is required by the graphics driver and copied to the instance buffer.
    Attribs.pInstances    = Instances;
    Attribs.InstanceCount = _countof(Instances);

    // Bind hit shaders per instance, it allows you to change the number of geometries in BLAS without invalidating the shader binding table.
    Attribs.BindingMode    = HIT_GROUP_BINDING_MODE_PER_INSTANCE;
    Attribs.HitGroupStride = HIT_GROUP_STRIDE;

    // Allow engine to change resource states.
    Attribs.TLASTransitionMode           = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
    Attribs.BLASTransitionMode           = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
    Attribs.InstanceBufferTransitionMode = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;
    Attribs.ScratchBufferTransitionMode  = RESOURCE_STATE_TRANSITION_MODE_TRANSITION;

    m_pImmediateContext->BuildTLAS(Attribs);
}

void Tutorial21_RayTracing::CreateSBT()
{
    // Create shader binding table.

    ShaderBindingTableDesc SBTDesc;
    SBTDesc.Name = "SBT";
    SBTDesc.pPSO = m_pRayTracingPSO;

    m_pDevice->CreateSBT(SBTDesc, &m_pSBT);
    VERIFY_EXPR(m_pSBT != nullptr);

    m_pSBT->BindRayGenShader("Main");

    m_pSBT->BindMissShader("PrimaryMiss", PRIMARY_RAY_INDEX);
    m_pSBT->BindMissShader("ShadowMiss", SHADOW_RAY_INDEX);

    // Hit groups for primary ray
    // clang-format off
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 1", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 2", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 3", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 4", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Ground Instance", PRIMARY_RAY_INDEX, "GroundHit"       );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 2", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 3", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 4", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 5", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 6", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 7", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 8", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 9", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 10", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 11", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 12", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 13", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 14", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 15", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 16", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 17", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 18", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 19", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 20", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 21", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 22", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 23", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 24", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 25", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 26", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 27", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 28", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 29", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 30", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 31", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 32", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 33", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 34", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 35", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 36", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 37", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 38", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 39", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 40", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 41", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 42", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 43", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 44", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 45", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 46", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 47", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 48", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 49", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 50", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 51", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 52", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 53", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 54", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 55", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 56", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 57", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 58", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 59", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 60", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 61", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 62", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 63", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 64", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 65", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 66", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 67", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 68", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 69", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 70", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 71", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 72", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 73", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 74", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 75", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 76", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 77", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 78", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 79", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 80", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 81", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 82", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 83", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 84", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 85", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 86", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 87", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 88", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 89", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 90", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 91", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 92", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 93", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 94", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 95", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 96", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 97", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 98", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 99", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 100", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 101", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 102", PRIMARY_RAY_INDEX, "SpherePrimaryHit");
m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance 103", PRIMARY_RAY_INDEX, "SpherePrimaryHit");

    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 2",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 3",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 4",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 5",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 6",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 7",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 8",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 9",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 10",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 11",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 12",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 13",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 14",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 15",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 16",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 17",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 18",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 19",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 20",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 21",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 22",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 23",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 24",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 25",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 26",  PRIMARY_RAY_INDEX, "GlassPrimaryHit" );

    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 27",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 28",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 29",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 30",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 31",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 32",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 33",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 34",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 35",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 36",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 37",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 38",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 39",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 40",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 41",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 42",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 43",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 44",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 45",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 46",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 47",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 48",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 49",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 50",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );    
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Glass Instance 51",  PRIMARY_RAY_INDEX, "CubePrimaryHit" );
    /*
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 5", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 6", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 7", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 8", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 9", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 10", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 11", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 12", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 13", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 14", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 15", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 16", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 17", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 18", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 19", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 20", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 21", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 22", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 23", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 24", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 25", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 26", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 27", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 28", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Cube Instance 29", PRIMARY_RAY_INDEX, "CubePrimaryHit"  );
  */

    // Hit groups for shadow ray.
    // null means no shaders are bound and hit shader invocation will be skipped.
    m_pSBT->BindHitGroupForTLAS(m_pTLAS, SHADOW_RAY_INDEX, nullptr);

    // We must specify the intersection shader for procedural geometry.
    m_pSBT->BindHitGroupForInstance(m_pTLAS, "Sphere Instance", SHADOW_RAY_INDEX, "SphereShadowHit");

    // Update SBT with the shader groups we bound
    m_pImmediateContext->UpdateSBT(m_pSBT);
}

void Tutorial21_RayTracing::Initialize(const SampleInitInfo& InitInfo)
{
    SampleBase::Initialize(InitInfo);

    if ((m_pDevice->GetAdapterInfo().RayTracing.CapFlags & RAY_TRACING_CAP_FLAG_STANDALONE_SHADERS) == 0)
    {
        UNSUPPORTED("Ray tracing shaders are not supported by device");
        return;
    }

    // Create a buffer with shared constants.
    BufferDesc BuffDesc;
    BuffDesc.Name      = "Constant buffer";
    BuffDesc.Size      = sizeof(m_Constants);
    BuffDesc.Usage     = USAGE_DEFAULT;
    BuffDesc.BindFlags = BIND_UNIFORM_BUFFER;

    m_pDevice->CreateBuffer(BuffDesc, nullptr, &m_ConstantsCB);
    VERIFY_EXPR(m_ConstantsCB != nullptr);

    CreateGraphicsPSO();
    CreateRayTracingPSO();
    LoadTextures();
    CreateCubeBLAS();
    CreateProceduralBLAS();
    UpdateTLAS();
    CreateSBT();

    // Setup camera.
    m_Camera.SetPos(float3(7.f, -0.5f, -16.5f));
    m_Camera.SetRotation(0.48f, -0.145f);
    m_Camera.SetRotationSpeed(0.005f);
    m_Camera.SetMoveSpeed(5.f);
    m_Camera.SetSpeedUpScales(5.f, 10.f);

    // Initialize constants.
    {
        m_Constants.ClipPlanes   = float2{0.1f, 100.0f};
        m_Constants.ShadowPCF    = 1;
        m_Constants.MaxRecursion = std::min(Uint32{6}, m_MaxRecursionDepth);

        // Sphere constants.
        m_Constants.SphereReflectionColorMask = {0.81f, 1.0f, 0.45f};
        m_Constants.SphereReflectionBlur      = 9;

        // Glass cube constants.
        m_Constants.GlassReflectionColorMask = {0.22f, 0.83f, 0.93f};
        m_Constants.GlassAbsorption          = 0.5f;
        m_Constants.GlassMaterialColor = {0.0f, 0.5f, 1.0f};  
        m_Constants.GlassIndexOfRefraction   = {1.5f, 1.02f};
        m_Constants.GlassEnableDispersion    = 0;

        // Wavelength to RGB and index of refraction interpolation factor.
        m_Constants.DispersionSamples[0]  = {0.140000f, 0.000000f, 0.266667f, 0.53f};
        m_Constants.DispersionSamples[1]  = {0.130031f, 0.037556f, 0.612267f, 0.25f};
        m_Constants.DispersionSamples[2]  = {0.100123f, 0.213556f, 0.785067f, 0.16f};
        m_Constants.DispersionSamples[3]  = {0.050277f, 0.533556f, 0.785067f, 0.00f};
        m_Constants.DispersionSamples[4]  = {0.000000f, 0.843297f, 0.619682f, 0.13f};
        m_Constants.DispersionSamples[5]  = {0.000000f, 0.927410f, 0.431834f, 0.38f};
        m_Constants.DispersionSamples[6]  = {0.000000f, 0.972325f, 0.270893f, 0.27f};
        m_Constants.DispersionSamples[7]  = {0.000000f, 0.978042f, 0.136858f, 0.19f};
        m_Constants.DispersionSamples[8]  = {0.324000f, 0.944560f, 0.029730f, 0.47f};
        m_Constants.DispersionSamples[9]  = {0.777600f, 0.871879f, 0.000000f, 0.64f};
        m_Constants.DispersionSamples[10] = {0.972000f, 0.762222f, 0.000000f, 0.77f};
        m_Constants.DispersionSamples[11] = {0.971835f, 0.482222f, 0.000000f, 0.62f};
        m_Constants.DispersionSamples[12] = {0.886744f, 0.202222f, 0.000000f, 0.73f};
        m_Constants.DispersionSamples[13] = {0.715967f, 0.000000f, 0.000000f, 0.68f};
        m_Constants.DispersionSamples[14] = {0.459920f, 0.000000f, 0.000000f, 0.91f};
        m_Constants.DispersionSamples[15] = {0.218000f, 0.000000f, 0.000000f, 0.99f};
        m_Constants.DispersionSampleCount = 4;

        m_Constants.AmbientColor  = float4(1.f, 1.f, 1.f, 0.f) * 0.015f;
        m_Constants.LightPos[0]   = {8.00f, +8.0f, +0.00f, 0.f};
        m_Constants.LightColor[0] = {1.00f, +0.8f, +0.80f, 0.f};
        m_Constants.LightPos[1]   = {0.00f, +4.0f, -5.00f, 0.f};
        m_Constants.LightColor[1] = {0.85f, +1.0f, +0.85f, 0.f};

        // Random points on disc.
        m_Constants.DiscPoints[0] = {+0.0f, +0.0f, +0.9f, -0.9f};
        m_Constants.DiscPoints[1] = {-0.8f, +1.0f, -1.1f, -0.8f};
        m_Constants.DiscPoints[2] = {+1.5f, +1.2f, -2.1f, +0.7f};
        m_Constants.DiscPoints[3] = {+0.1f, -2.2f, -0.2f, +2.4f};
        m_Constants.DiscPoints[4] = {+2.4f, -0.3f, -3.0f, +2.8f};
        m_Constants.DiscPoints[5] = {+2.0f, -2.6f, +0.7f, +3.5f};
        m_Constants.DiscPoints[6] = {-3.2f, -1.6f, +3.4f, +2.2f};
        m_Constants.DiscPoints[7] = {-1.8f, -3.2f, -1.1f, +3.6f};
    }
    static_assert(sizeof(HLSL::Constants) % 16 == 0, "must be aligned by 16 bytes");
}

void Tutorial21_RayTracing::ModifyEngineInitInfo(const ModifyEngineInitInfoAttribs& Attribs)
{
    SampleBase::ModifyEngineInitInfo(Attribs);

    // Require ray tracing feature.
    Attribs.EngineCI.Features.RayTracing = DEVICE_FEATURE_STATE_ENABLED;
}

// Render a frame
void Tutorial21_RayTracing::Render()
{
    UpdateTLAS();

    // Update constants
    {
        float3 CameraWorldPos = float3::MakeVector(m_Camera.GetWorldMatrix()[3]);
        auto   CameraViewProj = m_Camera.GetViewMatrix() * m_Camera.GetProjMatrix();

        m_Constants.CameraPos   = float4{CameraWorldPos, 1.0f};
        m_Constants.InvViewProj = CameraViewProj.Inverse();

        m_pImmediateContext->UpdateBuffer(m_ConstantsCB, 0, sizeof(m_Constants), &m_Constants, RESOURCE_STATE_TRANSITION_MODE_TRANSITION);
    }

    // Trace rays
    {
        m_pRayTracingSRB->GetVariableByName(SHADER_TYPE_RAY_GEN, "g_ColorBuffer")->Set(m_pColorRT->GetDefaultView(TEXTURE_VIEW_UNORDERED_ACCESS));

        m_pImmediateContext->SetPipelineState(m_pRayTracingPSO);
        m_pImmediateContext->CommitShaderResources(m_pRayTracingSRB, RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

        TraceRaysAttribs Attribs;
        Attribs.DimensionX = m_pColorRT->GetDesc().Width;
        Attribs.DimensionY = m_pColorRT->GetDesc().Height;
        Attribs.pSBT       = m_pSBT;

        m_pImmediateContext->TraceRays(Attribs);
    }

    // Blit to swapchain image
    {
        m_pImageBlitSRB->GetVariableByName(SHADER_TYPE_PIXEL, "g_Texture")->Set(m_pColorRT->GetDefaultView(TEXTURE_VIEW_SHADER_RESOURCE));

        auto* pRTV = m_pSwapChain->GetCurrentBackBufferRTV();
        m_pImmediateContext->SetRenderTargets(1, &pRTV, nullptr, RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

        m_pImmediateContext->SetPipelineState(m_pImageBlitPSO);
        m_pImmediateContext->CommitShaderResources(m_pImageBlitSRB, RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

        m_pImmediateContext->Draw(DrawAttribs{3, DRAW_FLAG_VERIFY_ALL});
    }
}

void Tutorial21_RayTracing::Update(double CurrTime, double ElapsedTime)
{
    SampleBase::Update(CurrTime, ElapsedTime);
    UpdateUI();

    if (m_Animate)
    {
        m_AnimationTime += static_cast<float>(std::min(m_MaxAnimationTimeDelta, ElapsedTime));
    }

    m_Camera.Update(m_InputController, static_cast<float>(ElapsedTime));

    // Do not allow going underground
    auto oldPos = m_Camera.GetPos();
    if (oldPos.y < -5.7f)
    {
        oldPos.y = -5.7f;
        m_Camera.SetPos(oldPos);
        m_Camera.Update(m_InputController, 0.f);
    }
}

void Tutorial21_RayTracing::WindowResize(Uint32 Width, Uint32 Height)
{
    if (Width == 0 || Height == 0)
        return;

    // Update projection matrix.
    float AspectRatio = static_cast<float>(Width) / static_cast<float>(Height);
    m_Camera.SetProjAttribs(m_Constants.ClipPlanes.x, m_Constants.ClipPlanes.y, AspectRatio, PI_F / 4.f,
                            m_pSwapChain->GetDesc().PreTransform, m_pDevice->GetDeviceInfo().NDC.MinZ == -1);

    // Check if the image needs to be recreated.
    if (m_pColorRT != nullptr &&
        m_pColorRT->GetDesc().Width == Width &&
        m_pColorRT->GetDesc().Height == Height)
        return;

    m_pColorRT = nullptr;

    // Create window-size color image.
    TextureDesc RTDesc       = {};
    RTDesc.Name              = "Color buffer";
    RTDesc.Type              = RESOURCE_DIM_TEX_2D;
    RTDesc.Width             = Width;
    RTDesc.Height            = Height;
    RTDesc.BindFlags         = BIND_UNORDERED_ACCESS | BIND_SHADER_RESOURCE;
    RTDesc.ClearValue.Format = m_ColorBufferFormat;
    RTDesc.Format            = m_ColorBufferFormat;

    m_pDevice->CreateTexture(RTDesc, nullptr, &m_pColorRT);
}

void Tutorial21_RayTracing::UpdateUI()
{
    const float MaxIndexOfRefraction = 2.0f;
    const float MaxDispersion        = 0.5f;

    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_AlwaysAutoResize))
    {
        ImGui::Checkbox("Animate", &m_Animate);

            if (ImGui::Button("Toggle Reaccion"))
    {
        reaccion = !reaccion;
    }

        ImGui::Text("Use WASD to move camera");
        ImGui::SliderInt("Shadow blur", &m_Constants.ShadowPCF, 0, 16);
        ImGui::SliderInt("Max recursion", &m_Constants.MaxRecursion, 0, m_MaxRecursionDepth);

        ImGui::Separator();


        ImGui::Text("Sphere");
        ImGui::SliderInt("Reflection blur", &m_Constants.SphereReflectionBlur, 1, 16);
        ImGui::ColorEdit3("Color mask", m_Constants.SphereReflectionColorMask.Data(), ImGuiColorEditFlags_NoAlpha);
    }
    ImGui::End();
}

} // namespace Diligent