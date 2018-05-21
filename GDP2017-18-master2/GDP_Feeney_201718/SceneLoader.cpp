// This file is used to laod the models
#include "cGameObject.h"
#include <vector>
#include "Utilities.h"		// getRandInRange()
#include <glm/glm.hpp>
#include "globalGameStuff.h"

// For the cSimpleAssimpSkinnedMeshLoader class
#include "assimp/cSimpleAssimpSkinnedMeshLoader_OneMesh.h"

#include "cAnimationState.h"

extern std::vector< cGameObject* >  g_vecGameObjects;
extern cGameObject* g_pTheDebugSphere;

extern cGameObject* g_ExampleTexturedQuad;


//const float SURFACEOFGROUND = -10.0f;
//const float RIGHTSIDEWALL = 15.0f;
//const float LEFTSIDEWALL = -15.0f;



void LoadModelsIntoScene(void)
{

	//for ( int count = 0; count != 1; count++ )
	//{
	//	{// Dalek
	//		cGameObject* pDalek = new cGameObject();
	//		pDalek->friendlyName = "Big D";
	//		cPhysicalProperties physState;
	//		physState.position = glm::vec3(getRandInRange(-100,100), 0.0, getRandInRange(-100, 100));
	//		physState.setOrientationEulerAngles(glm::vec3(0.0, 0.0, 0.0f));
	//		pDalek->SetPhysState(physState);
	//		sMeshDrawInfo meshInfo;
	//		meshInfo.scale = 1.0;
	//		meshInfo.name = "dalek2005_xyz_uv_res_2.ply";
	//		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 0.0f));
	//		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 1.0f));
	//		meshInfo.setMeshOrientationEulerAngles(glm::vec3(-90.0f,0.0f,0.0f), true);
	//		pDalek->vecMeshes.push_back(meshInfo);
	//		::g_vecGameObjects.push_back(pDalek);
	//	}
	//}

	{// Room model (for stencil buffer example)
		::g_Room = new cGameObject();
		::g_Room->friendlyName = "Room";
		cPhysicalProperties physState;
		physState.position = glm::vec3(0.0f, -60.0, 0.0f);
		physState.setOrientationEulerAngles(glm::vec3(0.0, 0.0, 0.0f));
		::g_Room->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 1.0;
		meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
//		meshInfo.bDrawAsWireFrame = true;
//		meshInfo.bUseDebugColour = true;
//		meshInfo.debugDiffuseColour = glm::vec4( 0.0f, 1.0f, 1.0f, 1.0f );
		meshInfo.name = "HouseWithNormals.ply";
		//meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 1.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 1.0f));
		::g_Room->vecMeshes.push_back(meshInfo);
	}
	{// Stencil mask (matches frame for doorway in Room model)
		::g_RoomMaskForStencil = new cGameObject();
		::g_RoomMaskForStencil->friendlyName = "RoomDoorMask";
		cPhysicalProperties physState;
		physState.position = glm::vec3(0.0f, -60.0, 0.0f);
		physState.setOrientationEulerAngles(glm::vec3(0.0f, 0.0, 0.0f));
		::g_RoomMaskForStencil->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 1.0;
		::g_RoomMaskForStencil->myScreen = true;
		//meshInfo.bUseDebugColour = true;
		//meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		//meshInfo.bDrawAsWireFrame = true;
		meshInfo.name = "tv_normals_uv.ply";
		//meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 0.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 1.0f));
		::g_RoomMaskForStencil->vecMeshes.push_back(meshInfo);
	}

	{// Stencil mask (matches frame for doorway in Room model)
		::g_RoomMaskForStencil2 = new cGameObject();
		::g_RoomMaskForStencil2->friendlyName = "RoomDoorMask";
		cPhysicalProperties physState;
		physState.position = glm::vec3(0.0f, -60.0, 0.0f);
		physState.setOrientationEulerAngles(glm::vec3(0.0f, 0.0, 0.0f));
		::g_RoomMaskForStencil2->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 1.0;
		//meshInfo.bUseDebugColour = true;
		//meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		//meshInfo.bDrawAsWireFrame = true;
		meshInfo.name = "backpanel_normals_uv.ply";
		//meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 0.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.0f));
		::g_RoomMaskForStencil2->vecMeshes.push_back(meshInfo);
	}
	


	{
		::shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.integrationUpdateType = cPhysicalProperties::EXCLUDED_FROM_INTEGRATION;
		physState.mass = physState.inverseMass = 0.0f;	// Infinite
		physState.position.x = -5.0f;
		physState.position.y = -20.0f;
		physState.position.z = 0.0f;
		//		physState.position.y = -100.0f;
		physState.setRotationalSpeedEuler(glm::vec3(0.0f, 0.5f, 0.0f));
		::shiny->SetPhysState(physState);


		sMeshDrawInfo meshInfo;
		meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 0.0f);
		meshInfo.scale = 30.0f;
		meshInfo.name = "SphereRadius1";

		//meshInfo.scale = 0.65f;
		//meshInfo.name = "teapotUV";	

		// Make bunny reflective...
		meshInfo.bIsEnvirMapped = true;
		meshInfo.reflectBlendRatio = 0.2f;
		meshInfo.refractBlendRatio = 0.7f;
		meshInfo.coefficientRefract = 1.4f;

		//meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("barberton_etm_2001121_lrg.bmp", 1.0f));
		//meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("height_map_norway-height-map-aster-30m.bmp", 0.0f));
		::shiny->vecMeshes.push_back(meshInfo);
	}








	{// 2 sided quad
		::g_ExampleTexturedQuad = new cGameObject();
		::g_ExampleTexturedQuad->friendlyName = "quad";
		cPhysicalProperties physState;
		physState.position = glm::vec3(100.0f, 100.0, -250.0f);
		physState.setOrientationEulerAngles(glm::vec3(90.0f, 0.0, 0.0f));
		::g_ExampleTexturedQuad->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 75;
		meshInfo.setMeshOrientationEulerAngles(glm::vec3(0.0f, 0.0f, 0.0f)); 
//		meshInfo.debugDiffuseColour = glm::vec4( 0.0f, 1.0f, 0.0f, 1.0f );
//		meshInfo.bDrawAsWireFrame = true;
		meshInfo.name = "2SidedQuad";
		//meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 0.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 1.0f));
		::g_ExampleTexturedQuad->vecMeshes.push_back(meshInfo);
		//::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	}		

	
	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		shiny->friendlyName = "NCC-1701";
		physState.integrationUpdateType = cPhysicalProperties::EXCLUDED_FROM_INTEGRATION;
		physState.mass = physState.inverseMass = 0.0f;	// Infinite
		physState.position.z = 0;
		physState.position.x = 0;
		physState.position.y = 0;
		shiny->SetPhysState(physState);

		sMeshDrawInfo meshInfo;
		meshInfo.scale = 100.0f;
		meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		meshInfo.name = "Ship_Pack_WIP_mod - command_xyz_n_uv.obj";
		//meshInfo.debugDiffuseColour = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
		//meshInfo.bUseDebugColour = true;
		//meshInfo.bDrawAsWireFrame = true;
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 1.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.0f));
		shiny->vecMeshes.push_back(meshInfo);

		::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	}	
	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		shiny->friendlyName = "NCC-1701";
		physState.integrationUpdateType = cPhysicalProperties::EXCLUDED_FROM_INTEGRATION;
		physState.mass = physState.inverseMass = 0.0f;	// Infinite
		physState.position.z = 0;
		physState.position.x = 0;
		physState.position.y = -50;
		//physState.adjOrientationEulerAngles(0.0f,0.0f,)
		shiny->SetPhysState(physState);

		sMeshDrawInfo meshInfo;
		meshInfo.scale = 10.0f;
		meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		meshInfo.name = "house";
		//meshInfo.debugDiffuseColour = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
		//meshInfo.bUseDebugColour = true;
		//meshInfo.bDrawAsWireFrame = true;
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 1.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.0f));
		shiny->vecMeshes.push_back(meshInfo);

		::g_vecGameObjects.push_back(shiny);		// Fastest way to add
	}
	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		shiny->friendlyName = "NCC-1701";
		physState.integrationUpdateType = cPhysicalProperties::EXCLUDED_FROM_INTEGRATION;
		physState.mass = physState.inverseMass = 0.0f;	// Infinite
		physState.position.z = 0;
		physState.position.x = 0;
		physState.position.y = -50;
		//physState.adjOrientationEulerAngles(0.0f,0.0f,)
		shiny->SetPhysState(physState);

		sMeshDrawInfo meshInfo;
		meshInfo.scale = 10.0f;
		meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		meshInfo.name = "PlaneXZ";
		//meshInfo.debugDiffuseColour = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
		//meshInfo.bUseDebugColour = true;
		//meshInfo.bDrawAsWireFrame = true;
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 1.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.0f));
		shiny->vecMeshes.push_back(meshInfo);

		::g_vecGameObjects.push_back(shiny);		// Fastest way to add
	}
	//
	
	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.integrationUpdateType = cPhysicalProperties::EXCLUDED_FROM_INTEGRATION;
		physState.mass = physState.inverseMass = 0.0f;	// Infinite
		physState.position.x = 75.0f;
		physState.position.y = 25.0f;
//		physState.position.y = -100.0f;
		physState.setRotationalSpeedEuler( glm::vec3(0.0f, 0.5f, 0.0f) );
		shiny->SetPhysState(physState);


		sMeshDrawInfo meshInfo;
		meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		meshInfo.scale = 1.0f;
		meshInfo.name = "bunny";	

		//meshInfo.scale = 0.65f;
		//meshInfo.name = "teapotUV";	

		// Make bunny reflective...
		meshInfo.bIsEnvirMapped = true;
		meshInfo.reflectBlendRatio = 0.5f;
		meshInfo.refractBlendRatio = 0.5f;
		meshInfo.coefficientRefract = 0.1f;

		// 
		shiny->friendlyName = "bugs";

		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("barberton_etm_2001121_lrg.bmp", 1.0f));
		meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("height_map_norway-height-map-aster-30m.bmp", 0.0f));
		shiny->vecMeshes.push_back(meshInfo);

		::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	}	
	//{
	//	cGameObject* shiny = new cGameObject();
	//	cPhysicalProperties physState;
	//	physState.integrationUpdateType = cPhysicalProperties::EXCLUDED_FROM_INTEGRATION;
	//	physState.mass = physState.inverseMass = 0.0f;	// Infinite
	//	physState.position.y = -100.0f;
	//	shiny->SetPhysState(physState);

	//	sMeshDrawInfo meshInfo;
	//	meshInfo.scale = 1.0f;
	//	meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
	//	meshInfo.name = "MeshLabTerrain_xyz_n_uv";	
	//	meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 1.0f));
	//	meshInfo.vecMehs2DTextures.push_back(sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.0f));
	//	shiny->vecMeshes.push_back(meshInfo);

	//	::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	//}
	//{	// Right side plane
	//	cGameObject* shiny = new cGameObject();
	//	shiny->position.x = 15.0f;	// RIGHTSIDEWALL;		// Where our physics HACK detection is
	//	shiny->orientation.z = glm::radians(0.0f);	// Degrees
	//	shiny->orientation2.z = glm::radians(90.0f);	// Degrees   
	//	shiny->scale = 1.0f;
	//	shiny->diffuseColour = glm::vec4( 0.0f, 1.0f, 1.0f, 1.0f );
	//	shiny->meshName = "PlaneXZ";		// Was teapot
	//	shiny->typeOfObject = eTypeOfObject::PLANE;
	//	// ***
	//	shiny->bIsUpdatedInPhysics = false;	
	//	// ***
	//	::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	//}

	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.position = glm::vec3(-4.0f, 4.0f, 0.0f);
		physState.velocity = glm::vec3(2.0f, 1.0f, 0.0f);
		physState.setOrientationEulerAngles(glm::vec3(0.0f, 0.0f, 0.0f));
		physState.rigidBodyShape = cPhysicalProperties::SPHERE;
		physState.rigidBodyMeasurements.sphere_capsule_radius = 1.0f;
		shiny->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 3.0f;
		meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		meshInfo.name = "SphereRadius1";
		shiny->vecMeshes.push_back(meshInfo);
		//
		::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	}	


	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.position = glm::vec3(-600.0f, 0.0f, 0.0f);
	//	physState.velocity = glm::vec3(3.0f, 1.0f, 0.0f);
		physState.setOrientationEulerAngles(glm::vec3(0.0f, 0.0f, 0.0f));
		//physState.rigidBodyShape = cPhysicalProperties::SPHERE;
		physState.rigidBodyMeasurements.sphere_capsule_radius = 1.0f;
		shiny->friendlyName = "myTV";
		shiny->SetPhysState(physState);
		shiny->myScreen = true;
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 10.0f;
		meshInfo.bUseDebugColour = false;
		meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		meshInfo.name = "tv";
		shiny->vecMeshes.push_back(meshInfo);
		//
		::g_vecGameObjects.push_back(shiny);		// Fastest way to add
	}



	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.position = glm::vec3(900.0f, 0.0f, 0.0f);
	//	physState.velocity = glm::vec3(2.0f, 1.0f, 0.0f);
		physState.setOrientationEulerAngles(glm::vec3(0.0f, 0.0f, 0.0f));
		//physState.rigidBodyShape = cPhysicalProperties::SPHERE;
		//physState.rigidBodyMeasurements.sphere_capsule_radius = 1.0f;
		shiny->friendlyName = "myTV1";
		shiny->SetPhysState(physState);
		shiny->myScreen1 = true;
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 10.0f;
		meshInfo.bUseDebugColour = false;
		meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		meshInfo.name = "tv";
		shiny->vecMeshes.push_back(meshInfo);
		//
		::g_vecGameObjects.push_back(shiny);		// Fastest way to add
	}





	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.position = glm::vec3(-0.5f, 4.0f, 0.0f);
		physState.rigidBodyShape = cPhysicalProperties::SPHERE;
		physState.rigidBodyMeasurements.sphere_capsule_radius = 1.0f;
		shiny->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 1.0f;
		meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		meshInfo.name = "SphereRadius1";			// was dolphin
		shiny->vecMeshes.push_back(meshInfo);
		::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	}
	// Add a bunch of spheres....
	for ( int count = 0; count != 0; count++ )
	{
		cGameObject* shiny = new cGameObject();
		cPhysicalProperties physState;
		physState.position.x = getRandInRange<float>(-7.0f, 7.0f);	
		physState.position.y = getRandInRange<float>( 1.0f, 10.0f ); 
		physState.velocity.x = getRandInRange<float>( -3.0f, 3.0f );
		physState.velocity.y = getRandInRange<float>( -1.0f, 2.0f );
		physState.rigidBodyShape = cPhysicalProperties::SPHERE;
		physState.rigidBodyMeasurements.sphere_capsule_radius = 1.0f;
		shiny->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 1.0f;
		meshInfo.debugDiffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
		meshInfo.name = "SphereRadius1";
		shiny->vecMeshes.push_back(meshInfo);
		//
		::g_vecGameObjects.push_back( shiny );		// Fastest way to add
	}// for ( int count...

	// Teapots at the bottom of vector, so are drawn last...
	{	// Teapot #1
		cGameObject* shiny = new cGameObject();
		shiny->friendlyName = LEFTTEAPOTNAME;
		cPhysicalProperties physState;
		physState.position.x = 4.0f;
		physState.integrationUpdateType = cPhysicalProperties::ePhysicsIntegrationUpdateTypes::EXCLUDED_FROM_INTEGRATION;
		shiny->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 0.1f;
		meshInfo.name = "teapotUV";	
		meshInfo.globalAlpha = 0.75f;
		meshInfo.vecMehs2DTextures.push_back( sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.0f) );
		meshInfo.vecMehs2DTextures.push_back( sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 1.0f) );
		shiny->vecMeshes.push_back(meshInfo);
		//
		::g_vecGameObjects.push_back(shiny);		// Fastest way to add
	}
	{	// Teapot #2
		cGameObject* shiny = new cGameObject();
		shiny->friendlyName = "Right Teapot";
		cPhysicalProperties physState;
		physState.position.x = -4.0f;
		physState.integrationUpdateType = cPhysicalProperties::ePhysicsIntegrationUpdateTypes::EXCLUDED_FROM_INTEGRATION;
		shiny->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 0.1f;
		meshInfo.name = "teapotUV";		
		meshInfo.globalAlpha = 0.75f;
		meshInfo.vecMehs2DTextures.push_back( sTextureBindBlendInfo("Utah_Teapot_xyz_n_uv_Enterprise.bmp", 0.5f) );
		meshInfo.vecMehs2DTextures.push_back( sTextureBindBlendInfo("GuysOnSharkUnicorn.bmp", 0.5f) );
		shiny->vecMeshes.push_back(meshInfo);
		//
		::g_vecGameObjects.push_back(shiny);		// Fastest way to add

	}

	// Our skybox object
	{
		//cGameObject* shiny = new cGameObject();
		::g_pSkyBoxObject = new cGameObject();
		cPhysicalProperties physState;
		::g_pSkyBoxObject->SetPhysState(physState);
		sMeshDrawInfo meshInfo;
		meshInfo.scale = 10000.0f;
		meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		meshInfo.name = "SmoothSphereRadius1InvertedNormals";			
		meshInfo.vecMeshCubeMaps.push_back(sTextureBindBlendInfo("green", 1.0f));
		meshInfo.bIsSkyBoxObject = true;
		::g_pSkyBoxObject->vecMeshes.push_back(meshInfo);
		// IS SKYBOX
		::g_vecGameObjects.push_back(::g_pSkyBoxObject);		// Fastest way to add
	}




	//// HACK: Set the objects to random colours
	//for ( int index = 0; index != ::g_vecGameObjects.size(); index++ )
	//{
	//	::g_vecGameObjects[index]->diffuseColour.r = getRandInRange(0.0f, 1.0f);
	//	::g_vecGameObjects[index]->diffuseColour.g = getRandInRange(0.0f, 1.0f);
	//	::g_vecGameObjects[index]->diffuseColour.b = getRandInRange(0.0f, 1.0f);
	//}

	//// HACK: Set texture values to something if there isn't a name
	//for (int index = 0; index != ::g_vecGameObjects.size(); index++)
	//{
	//	if (::g_vecGameObjects[index]->textureNames[0] == "")
	//	{
	//		::g_vecGameObjects[index]->textureNames[0] = "Utah_Teapot_xyz_n_uv_Enterprise.bmp";
	//		::g_vecGameObjects[index]->textureNames[1] = "GuysOnSharkUnicorn.bmp";
	//		::g_vecGameObjects[index]->textureBlend[0] = getRandInRange(0.0f, 1.0f);
	//		::g_vecGameObjects[index]->textureBlend[1] = 1.0f - ::g_vecGameObjects[index]->textureBlend[0];
	//	}
	//}//for (int index = 0; index 



//	// Add a bunch more rabbits
//	const float SIZEOFWORLD = 6.0f;	
////	for ( int index = 3; index < MAXNUMBEROFGAMEOBJECTS; index++ )
//	for ( int index = 3; index < 100; index++ )
//	{
//		cGameObject* shiny = new cGameObject();
//		shiny->position.x = getRandInRange<float>(-SIZEOFWORLD, SIZEOFWORLD );
//		shiny->position.y = getRandInRange<float>(-SIZEOFWORLD, SIZEOFWORLD );
//		shiny->position.z = getRandInRange<float>(-SIZEOFWORLD, SIZEOFWORLD );
//		//::g_GameObjects[index]->scale = getRandInRange<float>( 7.0f, 15.0f );
//		// Pick a random colour for this bunny
//		shiny->diffuseColour.r = getRandInRange<float>(0.0f, 1.0f );
//		shiny->diffuseColour.g = getRandInRange<float>(0.0f, 1.0f );
//		shiny->diffuseColour.b = getRandInRange<float>(0.0f, 1.0f );
//		shiny->meshName = "bunny";
//		::g_vecGameObjects.push_back( shiny );
//	}


//  // Add the debug sphere
//  {// STARTOF: Add the debug sphere
//  	::g_pTheDebugSphere = new cGameObject();
//  	::g_pTheDebugSphere->scale = 1.0f;
//  	::g_pTheDebugSphere->diffuseColour = glm::vec4( 1.0f, 1.0f, 1.0f, 1.0f );
//  	::g_pTheDebugSphere->meshName = "SphereRadius1";
//  	::g_pTheDebugSphere->typeOfObject = eTypeOfObject::SPHERE;
//  	::g_pTheDebugSphere->radius = 1.0f;	
//  	::g_pTheDebugSphere->bIsUpdatedInPhysics = false;
//  	// NOTE: I'm NOT adding it to the vector of objects
//  	//::g_vecGameObjects.push_back( shiny );		// Fastest way to add
//  }// ENDOF: Add the debug sphere


	//// Add a whole bunch of spheres!
	//float limit = 200.0f;
	//float step = 25.0f;
	//for ( float x = -limit; x <= limit; x += step )
	//{
	//	for ( float y = -limit; y <= limit; y += step )
	//	{
	//		for ( float z = -limit; z <= limit; z += step )
	//		{
	//			cGameObject* shiny = new cGameObject();
	//			cPhysicalProperties physState;
	//			physState.position = glm::vec3(x, y, z);
	//			physState.rigidBodyShape = cPhysicalProperties::SPHERE;
	//			physState.rigidBodyMeasurements.sphere_capsule_radius = 1.0f;
	//			shiny->SetPhysState(physState);
	//			sMeshDrawInfo meshInfo;
	//			meshInfo.scale = step / 16.0f;
	//			meshInfo.debugDiffuseColour = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	//			meshInfo.name = "SphereRadius1";			// was dolphin
	//			shiny->vecMeshes.push_back(meshInfo);
	//			::g_vecGameObjects.push_back(shiny);		// Fastest way to add
	//		}
	//	}
	//}

	
	
	return;
}
