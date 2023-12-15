// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPUSkinPublicDefs.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "Components/SceneComponent.h"
#include "Engine/TextureStreamingTypes.h"
#include "Components/MeshComponent.h"
#include "Containers/SortedMap.h"

class UVertexAnimProfile;
class UDebugSkelMeshComponent;
class UTextureRenderTarget2D;
class UAnimSequence;

class FPrimitiveSceneProxy;
class FColorVertexBuffer;
class FSkinWeightVertexBuffer;
class FSkeletalMeshRenderData;
class FSkeletalMeshLODRenderData;
struct FSkelMeshRenderSection;
class FPositionVertexBuffer;

class VERTEXANIMTOOLSETEDITOR_API FVATEditorUtils
{
public:
    static float PackBits(const uint32& bit);
    static int UnPackBits(const float bit);

    static void DoBakeProcess(USkeletalMeshComponent* PreviewComponent);
	static void DoBakeProcess_Programmatic(
        USkeletalMeshComponent* PreviewComponent,
	    UVertexAnimProfile* Profile,
        FString PackageName,
        bool bOnlyCreateStaticMesh, 
        bool DoAnimBake, 
        bool DoStaticMesh
    );
    
    static UStaticMesh* ConvertSkeletalMeshToStaticMesh(
        USkeletalMesh* SkeletalMesh,
        const FString PackageName,
        const int32 LODIndex
    );

    static void IntoIslands(
        const TArray <int32>& IndexBuffer,
        const TArray <FVector2D>& UVs, 
        TArray <int32>& OutIslandIDs, 
        int32& OutNumIslands
    );

    static void ClosestUVPivotAssign(
        const TArray <int32>& IndexBuffer, 
        const TArray <FVector2D>& UVs, 
        const TArray <FVector2D>& PivotUVPos, 
        TArray <int32>& VertPivotIDs
    );
};


