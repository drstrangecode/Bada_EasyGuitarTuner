#include "MainForm.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui;
using namespace Osp::Ui::Animations;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Media;
using namespace Osp::Io;

MainForm::MainForm(void) {
	pPlayer = null;
}

MainForm::~MainForm(void) {
}

bool MainForm::Initialize() {
	Construct(L"IDF_MAINFORM");
	return true;
}

result MainForm::OnDraw(void) {
	result r = E_SUCCESS;

	Canvas* pCanvas = GetCanvasN();
	Rectangle rt = pCanvas->GetBounds();

	Application * app = Application::GetInstance();
	AppResource * res = app->GetAppResource();
	Bitmap * pBitmap = res->GetBitmapN(L"strato_background.png",
			BITMAP_PIXEL_FORMAT_ARGB8888);

	pCanvas->DrawBitmap(rt, *pBitmap);

	delete pBitmap;
	delete pCanvas;

	return r;

}

result MainForm::OnInitializing(void) {
	result r = E_SUCCESS;

	pRepeatSwitch = static_cast<CheckButton *>(GetControl(L"IDC_REPEATSWITCH"));
	pRepeatSwitch->SetActionId(ACTION_ID_REPEAT_ON, ACTION_ID_REPEAT_OFF);
	pRepeatSwitch->AddActionEventListener(*this);

	AddTouchEventListener(*this);

	return r;
}

result MainForm::OnTerminating(void) {
	result r = E_SUCCESS;

	if (pPlayer != null) {
		pPlayer->Stop();
		pPlayer->Close();
		delete pPlayer;
		pPlayer = null;
	}

	return r;
}

void MainForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId) {

	bool repeatOn;

	switch (actionId) {
	case ACTION_ID_REPEAT_ON:
		repeatOn = true;
		break;
	case ACTION_ID_REPEAT_OFF:
		repeatOn = false;
		break;
	}

	if (pPlayer != null) {
		pPlayer->SetLooping(repeatOn);
	}
}

void MainForm::OnPlayerBuffering(int percent) {
}

void MainForm::OnPlayerEndOfClip(void) {
}

void MainForm::OnPlayerErrorOccurred(PlayerErrorReason r) {
}

void MainForm::OnPlayerInterrupted(void) {
}

void MainForm::OnPlayerOpened(result r) {
}

void MainForm::OnPlayerReleased(void) {
}

void MainForm::OnPlayerSeekCompleted(result r) {
}

void MainForm::OnTouchDoublePressed(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

}

void MainForm::OnTouchFocusIn(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

}

void MainForm::OnTouchFocusOut(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

}

void MainForm::OnTouchLongPressed(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

}

void MainForm::OnTouchMoved(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

}

void MainForm::OnTouchPressed(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

}

void MainForm::OnTouchReleased(const Osp::Ui::Control &source,
		const Osp::Graphics::Point &currentPosition,
		const Osp::Ui::TouchEventInfo &touchInfo) {

	AppLog("MainForm::OnTouchReleased()");

	if (pPlayer != null) {
		pPlayer->Stop();
		pPlayer->Close();
		delete pPlayer;
		pPlayer = null;
	}

	String toneFilePath;

	if (currentPosition.x >= 58 && currentPosition.x <= 58 + 42)
		toneFilePath = L"/Home/e.wav";
	else if (currentPosition.x >= 122 && currentPosition.x <= 122 + 42)
		toneFilePath = L"/Home/a.wav";
	else if (currentPosition.x >= 188 && currentPosition.x <= 188 + 42)
		toneFilePath = L"/Home/d.wav";
	else if (currentPosition.x >= 255 && currentPosition.x <= 255 + 42)
		toneFilePath = L"/Home/g.wav";
	else if (currentPosition.x >= 314 && currentPosition.x <= 314 + 42)
		toneFilePath = L"/Home/b.wav";
	else if (currentPosition.x >= 381 && currentPosition.x <= 381 + 42)
		toneFilePath = L"/Home/e1.wav";

	/* Create the audio player */
	pPlayer = new Player();
	pPlayer->Construct(*this, 0);

	/* Open file synchronously */
	pPlayer->OpenFile(toneFilePath, false);
	pPlayer->SetLooping(pRepeatSwitch->IsSelected());
	pPlayer->SetVolume(100);
	pPlayer->Play();

}

