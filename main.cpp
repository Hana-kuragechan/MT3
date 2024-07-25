#include <Novice.h>
#include"function.h"
#include<imgui.h>
const char kWindowTitle[] = "GC_2B_10_タムラ_ハナコ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f };
	Vector3 cameraPosition{ 0.0f,0.0f,-5.0f };
	Vector3 rotate{};
	Vector3 translate{};

	AABB aabb{
		.min{-0.5f, -0.5f, -0.5f},
		.max{0.5f, 0.5f, 0.5f},
	};

	Segment segment{
		.origin{-0.7f,0.3f,0.0f},
		.diff{2.0f,-0.5f,0.0f},
	};
	
	uint32_t color = WHITE;
	Vector3 start;
	Vector3 end;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		/// 

		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);


		if (IsCollision(aabb, segment)) {
			color = RED;
		}
		else {
			color = WHITE;
		}
		ImGui::DragFloat3("cameraRotate", &cameraRotate.x, 0.01f);
		ImGui::DragFloat3("cameraTranslate", &cameraTranslate.x, 0.01f);

		ImGui::DragFloat3("aabb.min.", &aabb.min.x, 0.01f);
		ImGui::DragFloat3("aabb.max.", &aabb.max.x, 0.01f);
		ImGui::DragFloat3("segment.origin", &segment.origin.x, 0.01f);
		ImGui::DragFloat3("segment.diff", &segment.diff.x, 0.01f);

		aabb.min.x = (std::min)(aabb.min.x, aabb.max.x);
		aabb.min.y = (std::min)(aabb.min.y, aabb.max.y);
		aabb.min.z = (std::min)(aabb.min.z, aabb.max.z);
		aabb.max.x = (std::max)(aabb.min.x, aabb.max.x);
		aabb.max.y = (std::max)(aabb.min.y, aabb.max.y);
		aabb.max.z = (std::max)(aabb.min.z, aabb.max.z);

		start = Transform(Transform(segment.origin, worldViewProjectionMatrix), viewportMatrix);
		end = Transform(Transform(Add(segment.origin, segment.diff), worldViewProjectionMatrix), viewportMatrix);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		DrawAABB(aabb, worldViewProjectionMatrix, viewportMatrix, WHITE);
		Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), color);
		DrawGrid(worldViewProjectionMatrix, viewportMatrix);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
