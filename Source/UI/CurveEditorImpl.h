#pragma once
#include "CurveEditor.h"
#include "CurvePoint.h"

class CCurveEditorImpl : public CurveEditor {
  public:
    CCurveEditorImpl();
    virtual ~CCurveEditorImpl();

    void paint(Graphics &g) override;

    void mouseDown(const MouseEvent &e) override;

    void mouseDrag(const MouseEvent &e) override;

    void mouseUp(const MouseEvent &e) override;

private:
    CCurvePoint* GetPointAt(const juce::Point& target);

    struct SParameters{
        float pointRadius = 5;
    } mParameters;

    std::vector<CCurvePoint> mPoints;
    juce::Path mCurvePath;
};