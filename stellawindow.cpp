#include "stellawindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollBar>

StellaWindow::StellaWindow(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Stella - Your Personal Star Companion ✨");
    resize(1000, 680);

    m_core = new StellaCore(this);
    m_speech = new QTextToSpeech(this);

    // Ayol ovozini tanlash
    for (const QVoice& voice : m_speech->availableVoices()) {
        if (voice.gender() == QVoice::Female || 
            voice.name().contains("female", Qt::CaseInsensitive) || 
            voice.name().contains("Samantha", Qt::CaseInsensitive)) {
            m_speech->setVoice(voice);
            break;
        }
    }

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);

    // Yulduz effekti
    m_starWidget = new ParticleEffect(this);
    m_starWidget->setMinimumWidth(450);
    mainLayout->addWidget(m_starWidget);

    // Chat qismi
    QVBoxLayout* chatLayout = new QVBoxLayout();
    mainLayout->addLayout(chatLayout, 1);

    m_chatArea = new QTextEdit(this);
    m_chatArea->setReadOnly(true);
    m_chatArea->setStyleSheet("background-color: #0a0a1f; color: #e0f0ff; font-size: 15px; padding: 10px;");
    chatLayout->addWidget(m_chatArea);

    QHBoxLayout* inputLayout = new QHBoxLayout();
    m_inputLine = new QLineEdit(this);
    m_inputLine->setPlaceholderText("Type your message here...");
    m_sendButton = new QPushButton("Send", this);
    m_sendButton->setDefault(true);

    inputLayout->addWidget(m_inputLine);
    inputLayout->addWidget(m_sendButton);
    chatLayout->addLayout(inputLayout);

    connect(m_sendButton, &QPushButton::clicked, this, &StellaWindow::onSendMessage);
    connect(m_inputLine, &QLineEdit::returnPressed, this, &StellaWindow::onSendMessage);

    // Birinchi salomlashuv
    QString greeting = m_core->getGreeting();
    m_chatArea->append("<b style='color:#00ffff'>Stella:</b> " + greeting);
    m_speech->say(greeting);
}

StellaWindow::~StellaWindow() {}

void StellaWindow::onSendMessage()
{
    QString text = m_inputLine->text().trimmed();
    if (text.isEmpty()) return;

    m_chatArea->append("<b style='color:#aaffff'>You:</b> " + text);
    m_inputLine->clear();

    QString reply = m_core->processInput(text);
    m_chatArea->append("<b style='color:#00ffff'>Stella:</b> " + reply);

    m_starWidget->setEmotion(m_core->getEmotion());
    m_speech->say(reply);

    m_chatArea->verticalScrollBar()->setValue(m_chatArea->verticalScrollBar()->maximum());
}
