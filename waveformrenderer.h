#ifndef WAVEFORMRENDERER_H
#define WAVEFORMRENDERER_H

#include <QLabel>
#include <QVector>

struct WaveformData {
    QVector<double> channel1;
    QVector<double> channel2;
};

enum TriggerType {
    NoTrigger,
    RisingEdge,
    FallingEdge,
    TriggerLevel
};

struct OscilloscopeSettings {
    TriggerType triggerType;
    double triggerLevel;
};

class WaveformRenderer
{
public:
    WaveformRenderer();

    void drawWaveform(QLabel *label, const QVector<double> &data);
    void analyzeWaveformData(const WaveformData &data);

    void setOscilloscopeSettings(const OscilloscopeSettings &settings);
    void setWaveformData(const WaveformData &data);
    void setZoomLevel(double level);
    void setGain(double gain);
    void setIsTrig1Hit(bool hit);
    void setIsTrig2Hit(bool hit);
    void setSnapShotData(const WaveformData &data);

private:
    OscilloscopeSettings m_oscSettings;
    WaveformData m_waveformData;
    double m_zoomLevel;
    double m_gain;
    bool m_isTrig1Hit;
    bool m_isTrig2Hit;
    WaveformData m_snapShotData;
};

#endif // WAVEFORMRENDERER_H
