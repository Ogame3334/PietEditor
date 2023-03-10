# include <Siv3D.hpp> // OpenSiv3D v0.6.6
#include "src/OgameWindow/ColorPalette/ColorPalette.h"
#include "src/User/User.h"
#include "src/Debug/Debug.h"
#include "src/OgameWindow/MenuBar/MenuBox.h"
#include "src/OgameWindow/MenuBar/MenuBar.h"
#include "src/OgameWindow/Canvas/Canvas.h"
#include "src/OgameWindow/Canvas/CanvasBackground.h"
#include "src/OgameWindow/StatusBar/StatusBar.h"
//#include "src/OgameGUI/OgameGUI.h"
#include "src/OgameWindow/TextBox/TextBoxMultipleLines.h"

void OptionSetting(void) {
	User::Setting::SetThemeID(0);
	Scene::SetBackground(User::Setting::GetTheme().GetBackGroundColor());
	Window::Resize(1280, 720);
	Window::SetStyle(WindowStyle::Sizable);
	Window::SetTitle(U"Ogame's PietEditor");
	Window::SetToggleFullscreenEnabled(false); // Alt + Enter封じ
	System::SetTerminationTriggers(UserAction::NoAction);
}

void UserInput(bool& isFullScreen, bool textBoxIsSelected) {
	if (KeyF3.down()) {
		if (Debug::isDebugMode) {
			Debug::isDebugMode = false;
		}
		else {
			Debug::isDebugMode = true;
		}
	}

	// System
	{
		const auto userAction = System::GetUserActions();
		if (userAction & UserAction::CloseButtonClicked) {
			System::Exit();
		}
	}

	{
		if (KeyF11.down()) {
			if (isFullScreen) {
				Window::SetFullscreen(false);
				isFullScreen = false;
			}
			else {
				Window::SetFullscreen(true);
				isFullScreen = true;
			}
		}
	}

	{
		if (User::Setting::GetInputMode() == 2 and not textBoxIsSelected) {
			if (KeyQ.down()) {
				User::State::SetDrawingColorID(0);
				User::State::SetSelectedColorID(0);
			}
			if (KeyW.down()) {
				User::State::SetDrawingColorID(1);
				User::State::SetSelectedColorID(1);
			}
			if (KeyE.down()) {
				User::State::SetDrawingColorID(2);
				User::State::SetSelectedColorID(2);
			}
			if (KeyR.down()) {
				User::State::SetDrawingColorID(3);
				User::State::SetSelectedColorID(3);
			}
			if (KeyT.down()) {
				User::State::SetDrawingColorID(4);
				User::State::SetSelectedColorID(4);
			}
			if (KeyY.down()) {
				User::State::SetDrawingColorID(5);
				User::State::SetSelectedColorID(5);
			}
			if (KeyA.down()) {
				User::State::SetDrawingColorID(6);
				User::State::SetSelectedColorID(6);
			}
			if (KeyS.down()) {
				User::State::SetDrawingColorID(7);
				User::State::SetSelectedColorID(7);
			}
			if (KeyD.down()) {
				User::State::SetDrawingColorID(8);
				User::State::SetSelectedColorID(8);
			}
			if (KeyF.down()) {
				User::State::SetDrawingColorID(9);
				User::State::SetSelectedColorID(9);
			}
			if (KeyG.down()) {
				User::State::SetDrawingColorID(10);
				User::State::SetSelectedColorID(10);
			}
			if (KeyH.down()) {
				User::State::SetDrawingColorID(11);
				User::State::SetSelectedColorID(11);
			}
			if (KeyZ.down()) {
				User::State::SetDrawingColorID(12);
				User::State::SetSelectedColorID(12);
			}
			if (KeyX.down()) {
				User::State::SetDrawingColorID(13);
				User::State::SetSelectedColorID(13);
			}
			if (KeyC.down()) {
				User::State::SetDrawingColorID(14);
				User::State::SetSelectedColorID(14);
			}
			if (KeyV.down()) {
				User::State::SetDrawingColorID(15);
				User::State::SetSelectedColorID(15);
			}
			if (KeyB.down()) {
				User::State::SetDrawingColorID(16);
				User::State::SetSelectedColorID(16);
			}
			if (KeyN.down()) {
				User::State::SetDrawingColorID(17);
				User::State::SetSelectedColorID(17);
			}
			if (KeyU.down()) {
				User::State::SetDrawingColorID(18);
			}
			if (KeyJ.down()) {
				User::State::SetDrawingColorID(19);
			}
		}
	}
}

void Main(){

	bool isFullScreen = false;

	OgameWindow::MenuBar menuBar{};
	OgameWindow::ColorPalette colorPalette{ Point(10, 35) };
	OgameWindow::Canvas canvas{ Point(colorPalette.GetSize().x + colorPalette.GetPosition().x + 10, 35) };
	OgameWindow::StatusBar statusBar{};
	OgameWindow::TextBoxMultipleLines inputTextBox{ true };
	OgameWindow::TextBoxMultipleLines outputTextBox{ false };

	//OgameWindow::ScrollBar scrollBar{ 16, 200 , 10, 200};
	//OgameWindow::MenuBox menuBox{ 150 };
	//bool isJapanese = User::Setting::GetIsJapanese();
	//menuBox.Append(OgameWindow::MenuButton(U"Save", (isJapanese) ? U"保存" : U"Save", menuBox.GetWidth()));
	//menuBox.Append(OgameWindow::MenuButton(U"Exit", (isJapanese) ? U"終了" : U"Exit", menuBox.GetWidth()));

	OptionSetting();

	Font debugFont{ 16 };
	Point debugPos{ 0, 0 };

	//Console << U"";

	String text;

	//TextEditState tempda;

	//constexpr Rect area{ 50, 50, 700, 300 };

	while (System::Update()) {
		User::State::SetNowSelectObjectID(-1);

		UserInput(isFullScreen, inputTextBox.GetIsSelected());

		canvas.Update(Point(colorPalette.GetSize().x + colorPalette.GetPosition().x + 10, 35));
		colorPalette.Update(Point(10, 35));
		statusBar.Update(canvas);

		Point temp = canvas.GetPosition() + Point(0, canvas.GetBackground().size.y + 50);
		inputTextBox.Update(temp, Point((Scene::Size().x - temp.x - 20) / 2 - 5, Scene::Size().y - temp.y - statusBar.Height - 30));

		temp = canvas.GetPosition() + Point(inputTextBox.GetSize().x + 10, canvas.GetBackground().size.y + 50);
		//outputTextBox.Update(temp, Point(inputTextBox.GetSize().x, Scene::Size().y - temp.y - statusBar.Height - 30));

		menuBar.Update(Point(0, 0));
		//menuBox.Update(Point(0, 20));
		//scrollBar.UpdateInt(Point(100, 100), 30);


		canvas.InputUpdate();
		colorPalette.InputUpdate();
		inputTextBox.InputUpdate();
		//outputTextBox.InputUpdate();
		menuBar.InputUpdate();
		//scrollBar.InputUpdate();

		canvas.Draw();
		colorPalette.Draw();
		statusBar.Draw();
		inputTextBox.Draw();
		//outputTextBox.Draw();
		menuBar.Draw();
		//scrollBar.Draw();

		//menuBox.Draw();

		//SimpleGUI::TextBox(tempda, Vec2(400, 400));

		//SimpleGUI::TextBoxMultipleLines(temp, Point(500, 200), Point(400, 600));

		Debug::Display(debugPos, debugFont);

		/*if (SimpleGUI::Button(U"Exit", Vec2{ 700, 20 }))
		{
			System::Exit();
		}*/


	}
}
