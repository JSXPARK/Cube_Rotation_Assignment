﻿#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define DEVICE Device::Get()->GetDevice()
#define DC     Device::Get()->GetDeviceContext()

#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

using namespace std;
using namespace DirectX;

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
typedef XMVECTOR Vector4;
typedef XMMATRIX Matrix;
typedef XMFLOAT4X4 Float4x4;

// Framework Header
#include "Framework/Utility/Singleton.h"

#include "Framework/Device/Device.h"

#include "Framework/Shader/Shader.h"
#include "Framework/Shader/VertexShader.h"
#include "Framework/Shader/PixelShader.h"

#include "Framework/Buffer/VertexBuffer.h"
#include "Framework/Buffer/IndexBuffer.h"
#include "Framework/Buffer/ConstBuffer.h"
#include "Framework/Buffer/VertexLayout.h"
#include "Framework/Buffer/GlobalBuffer.h"

// Object Header

// Scene Header
#include "Scenes/Scene.h"
#include "GameMgr.h"

extern HWND hWnd;