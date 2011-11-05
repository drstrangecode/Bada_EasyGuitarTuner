#ifndef _MAINFORM_H_
#define _MAINFORM_H_

#include <FBase.h>
#include <FGraphics.h>
#include <FUi.h>
#include <FUiAnimFrameAnimator.h>
#include <FMedia.h>
#include <FApp.h>
#include <FIo.h>

class MainForm: public Osp::Ui::Controls::Form,
		public Osp::Ui::IActionEventListener,
		public Osp::Ui::ITouchEventListener,
		public Osp::Media::IPlayerEventListener {

	// Construction
public:
	MainForm(void);
	virtual ~MainForm(void);
	bool Initialize(void);

	virtual result OnDraw();

private:
	Osp::Media::Player * pPlayer;

	/* Gui Controls */
	Osp::Ui::Controls::CheckButton * pRepeatSwitch;

	/* Action IDs */
	static const int ACTION_ID_REPEAT_ON = 101;
	static const int ACTION_ID_REPEAT_OFF = 102;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	/* IPlayerEventListener */
	virtual void OnPlayerBuffering(int percent);
	virtual void OnPlayerEndOfClip(void);
	virtual void OnPlayerErrorOccurred(Osp::Media::PlayerErrorReason r);
	virtual void OnPlayerInterrupted(void);
	virtual void OnPlayerOpened(result r);
	virtual void OnPlayerReleased(void);
	virtual void OnPlayerSeekCompleted(result r);


	/* ITouchEventListener */
	virtual void OnTouchDoublePressed(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchFocusIn(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchFocusOut(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchLongPressed(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchMoved(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchPressed(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

	virtual void OnTouchReleased(const Osp::Ui::Control &source,
			const Osp::Graphics::Point &currentPosition,
			const Osp::Ui::TouchEventInfo &touchInfo);

};

#endif	//_MAINFORM_H_
