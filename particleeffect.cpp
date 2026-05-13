#include "particleeffect.h"
#include <QPainter>
#include <QRandomGenerator>
#include <QTimer>

ParticleEffect::ParticleEffect(QWidget* parent) : QWidget(parent)
{
    setMinimumSize(420, 420);
    for (int i = 0; i < 120; ++i) {
        Star s;
        s.pos = QPointF(QRandomGenerator::global()->bounded(500), 
                       QRandomGenerator::global()->bounded(500));
        s.size = QRandomGenerator::global()->bounded(1.5, 5.0);
        s.speed = QRandomGenerator::global()->bounded(0.4, 2.0);
        m_stars.append(s);
    }
    m_timerId = startTimer(50);
}

void ParticleEffect::setEmotion(Emotion emotion)
{
    switch(emotion) {
        case Emotion::Happy:    m_color = Qt::yellow; break;
        case Emotion::Playful:  m_color = Qt::magenta; break;
        case Emotion::Upset:    m_color = Qt::red; break;
        default:                m_color = Qt::cyan; break;
    }
    update();
}

void ParticleEffect::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.fillRect(rect(), QColor(5, 5, 25));  // dark space background

    for (const auto& star : m_stars) {
        p.setPen(QPen(m_color, star.size));
        p.drawPoint(star.pos);
    }

    // Central bright star
    QRadialGradient grad(width()/2, height()/2, 45);
    grad.setColorAt(0, Qt::white);
    grad.setColorAt(1, m_color);
    p.setBrush(grad);
    p.setPen(Qt::NoPen);
    p.drawEllipse(width()/2 - 32, height()/2 - 32, 64, 64);
}

void ParticleEffect::timerEvent(QTimerEvent*)
{
    for (auto& star : m_stars) {
        star.pos.ry() += star.speed;
        if (star.pos.y() > height()) 
            star.pos.setY(0);
    }
    update();
}
