#include "DubStepGuiImpl.h"

CDubStepGuiImpl::CDubStepGuiImpl() {
    mPresetBrowser.reset(new CPresetBrowserImpl());
    mPresetListenerHandle = mPresetBrowser->AddListener(*this);
}

CDubStepGuiImpl::~CDubStepGuiImpl() {
    setLookAndFeel(nullptr);
}

void CDubStepGuiImpl::sliderValueChanged(Slider *sliderThatWasMoved) {
    if (mListener) {
        mListener->OnValueChanged(sliderThatWasMoved->getName().toStdString(), sliderThatWasMoved->getValue());
    }
}

void CDubStepGuiImpl::buttonClicked(Button *buttonClicked) {
    if (mListener) {
        mListener->OnValueChanged(buttonClicked->getName().toStdString(), buttonClicked->getToggleState());
    }
    /*if (buttonClicked == openPresetBrowser.get()) {
        addAndMakeVisible(*mPresetBrowser.get());
        mPresetBrowser->setBounds((getWidth() - mPresetBrowser->getWidth()) / 2, 0, mPresetBrowser->getWidth(), mPresetBrowser->getHeight());
    } else if (buttonClicked == mBtnPresetNext.get()) {
        mPresetBrowser->NextPreset();
    } else if (buttonClicked == mBtnPresetPrev.get()) {
        mPresetBrowser->PreviousPreset();
    }*/
}



void CDubStepGuiImpl::OnLoadPreset(const std::string &filePath) {
    if (mStateManager) {
        mStateManager->LoadStateFromFile(filePath);
    }

    //mBtnRename->setVisible(mStateManager->HasCurrentPath());
}

void CDubStepGuiImpl::Initialize(IGuiListener *listener, CSynthStateManager &stateManager) {
    mListener = listener;
    mStateManager = &stateManager;
}

void CDubStepGuiImpl::OnNameAndCategoryChanged() {
    //const auto& info = mStateManager->GetState().GetStateInfo();
    //mPresetDescr->setText(info.category + " / " + info.name, NotificationType::dontSendNotification);
    //mRenamePreset->SetNameAndCategory(info.name, info.category);
}
