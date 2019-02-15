#pragma once
#include "DubStepGui.h"

#include "VSTComponents/Owl/ISynthStateManagerListener.h"
#include "VSTComponents/PresetBrowser/PresetBrowserImpl.h"
#include "VSTComponents/OwlUI/IGuiListener.h"
#include "VSTComponents/PresetBrowser/IPresetBrowserListeners.h"
#include "VSTComponents/Owl/ListenerHandle.h"

class CDubStepGuiImpl : public DubStepGui, public IPresetBrowserListener, public ISynthStateManagerListener  {
 public:
	CDubStepGuiImpl();
	virtual ~CDubStepGuiImpl();
	void sliderValueChanged(Slider* sliderThatWasMoved) override;
	void buttonClicked(Button* buttonThatWasClicked) override;

	void Initialize(IGuiListener* listener, CSynthStateManager& stateManager);

private:
	std::unique_ptr<CPresetBrowserImpl> mPresetBrowser;
	//std::unique_ptr<CRenamePresetGuiImpl> mRenamePreset;
	IListenerHandle mPresetListenerHandle;
	IListenerHandle mStateManagerListenerHandle;

	IGuiListener * mListener = nullptr;
	CSynthStateManager* mStateManager;

	// Inherited via IPresetBrowserListener
	virtual void OnLoadPreset(const std::string & filePath) override;

	virtual void OnNameAndCategoryChanged() override;
};