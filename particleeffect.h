#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include <QWidget>
#include "stellacore.h"

struct Star {
    QPointF pos;
    double size;
    double speed;
};

class ParticleEffect : public QWidget
{
    Q_OBJECT
public:
    explicit ParticleEffect(QWidget* parent = nullptr);
    void setEmotion(Emotion emotion);

protected:
    void paintEvent(QPaintEvent* event) override;
    void timerEvent(QTimerEvent* event) override;

private:
    QVector<Star> m_stars;
    QColor m_color = Qt::cyan;
    int m_timerId;
};

#endif // PARTICLEEFFECT_H
