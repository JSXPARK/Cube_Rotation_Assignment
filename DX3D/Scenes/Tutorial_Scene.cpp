#include "Framework.h"
#include "Tutorial_Scene.h"

Tutorial_Scene::Tutorial_Scene()
{
	D3D11_VIEWPORT viewport = {};

	viewport.TopLeftX = 0.f;
	viewport.TopLeftY = 0.f;
	viewport.Width    = WIN_WIDTH;
	viewport.Height   = WIN_HEIGHT;
	viewport.MinDepth = 0.f;
	viewport.MaxDepth = 1.f;

	DC->RSSetViewports(1, &viewport);

	vertexShader = Shader::AddVS(L"Shaders/Tutorial.hlsl");
	pixelShader = Shader::AddPS(L"Shaders/Tutorial.hlsl");

	// 정점(Vertex) : 3D공간에서의 한 점
	// Polygon : 정점 3개로 이루어진 3차원 공간에서의 삼각형
	// 정점 순서에 따라서 시계방향이 앞면이며, 앞면만 출력
	vertices.emplace_back(-0.5f, +0.5f, -0.5f, 1.f, 1.f, 0.f);
	vertices.emplace_back(+0.5f, +0.5f, -0.5f, 0.f, 1.f, 0.f);
	vertices.emplace_back(-0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f);
	vertices.emplace_back(+0.5f, -0.5f, -0.5f, 0.f, 0.f, 1.f);
	vertices.emplace_back(-0.5f, +0.5f, +0.5f, 1.f, 1.f, 0.f);
	vertices.emplace_back(+0.5f, +0.5f, +0.5f, 0.f, 1.f, 0.f);
	vertices.emplace_back(-0.5f, -0.5f, +0.5f, 1.f, 0.f, 0.f);
	vertices.emplace_back(+0.5f, -0.5f, +0.5f, 0.f, 0.f, 1.f);

	vertexBuffer = new VertexBuffer(vertices.data(), sizeof(VertexColor), vertices.size());

	indices =
	{
		0, 1, 2, 1, 3, 2,
		0, 4, 5, 0, 5, 1,
		1, 5, 3, 3, 5, 7,
		7, 5, 4, 7, 4, 6,
		6, 4, 0, 6, 0, 2,
		6, 2, 3, 6, 3, 7
	};

	indexBuffer = new IndexBuffer(indices.data(), indices.size());

	worldBuffer = new MatrixBuffer();
	viewBuffer = new MatrixBuffer();
	projectionBuffer = new MatrixBuffer();

	Vector4 eye = XMVectorSet(3, 3, -5, 0);
	Vector4 focus = XMVectorSet(0, 0, 0, 0);
	Vector4 up = XMVectorSet(0, 1, 0, 0);

	Matrix view = XMMatrixLookAtLH(eye, focus, up);
	viewBuffer->Set(view);
	viewBuffer->SetVSBuffer(1);

	Matrix projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, WIN_WIDTH / (float)WIN_HEIGHT, 0.1f, 1000.f);
	projectionBuffer->Set(projection);
	projectionBuffer->SetVSBuffer(2);
}

Tutorial_Scene::~Tutorial_Scene()
{
	delete vertexBuffer;
	delete indexBuffer;

	delete worldBuffer;
	delete viewBuffer;
	delete projectionBuffer;
}

void Tutorial_Scene::Update()
{
	static float angle = 0.f;

	angle += 0.001f;

	world = XMMatrixRotationX(angle) * XMMatrixRotationY(angle) * XMMatrixRotationZ(angle);

	worldBuffer->Set(world);
}

void Tutorial_Scene::Render()
{
	worldBuffer->SetVSBuffer(0);

	vertexBuffer->IASet(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	indexBuffer->IASet();

	vertexShader->Set();
	pixelShader->Set();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Tutorial_Scene::GUIRender() {}