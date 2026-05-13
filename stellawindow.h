#ifndef STELLAWINDOW_H
#define STELLAWINDOW_H

#include <QMainWindow>
#include <QTextToSpeech>
#include "stellacore.h"
#include "particleeffect.h"

class QTextEdit;
class QLineEdit;
class QPushButton;

class StellaWindow : public QMainWindow
{
    Q_OBJECT
public:
    StellaWindow(QWidget* parent = nullptr);
    ~StellaWindow();

private slots:
    void onSendMessage();

private:
    StellaCore* m_core;
    QTextToSpeech* m_speech;
    ParticleEffect* m_starWidget;
    QTextEdit* m_chatArea;
    QLineEdit* m_inputLine;
    QPushButton* m_sendButton;
};

#endif // STELLAWINDOW_H
