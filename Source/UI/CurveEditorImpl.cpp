#include "CurveEditorImpl.h"

CCurveEditorImpl::CCurveEditorImpl() {

}

CCurveEditorImpl::~CCurveEditorImpl() {

}

void CCurveEditorImpl::paint(Graphics &g) {
    CurveEditor::paint(g);
}

void CCurveEditorImpl::mouseDown(const MouseEvent &e) {

}

void CCurveEditorImpl::mouseDrag(const MouseEvent &e) {

}

void CCurveEditorImpl::mouseUp(const MouseEvent &e) {

}

CCurvePoint *CCurveEditorImpl::GetPointAt(const juce::Point& target) {
    for(auto& point: mPoints) {
        if(point.getDistanceFrom(target)<mParameters.pointRadius) {
            return &point;
        }
    }

    return nullptr;
}
