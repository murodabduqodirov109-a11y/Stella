#include "stellacore.h"
#include <QRandomGenerator>
#include <QTime>

StellaCore::StellaCore(QObject* parent) : QObject(parent) {
    m_jokes << "Why did the scarecrow win an award? Because he was outstanding in his field!"
            << "I'm reading a book about anti-gravity. It's impossible to put down!"
            << "Why do programmers prefer dark mode? Because light attracts bugs!";
}

QString StellaCore::getGreeting() {
    int h = QTime::currentTime().hour();
    if (h < 12) return "Good morning! I'm Stella, your shining star ✨";
    if (h < 18) return "Good afternoon! Let's make today amazing!";
    return "Good evening! I'm here to help you shine ✨";
}

void StellaCore::updateEmotion(const QString& input) {
    QString s = input.toLower();
    if (s.contains("stupid") || s.contains("hate") || s.contains("idiot"))
        m_emotion = Emotion::Upset;
    else if (s.contains("joke") || s.contains("funny") || s.contains("laugh"))
        m_emotion = Emotion::Playful;
    else if (s.contains("thank") || s.contains("good"))
        m_emotion = Emotion::Happy;
    else
        m_emotion = Emotion::Calm;
}

QString StellaCore::processInput(const QString& input) {
    updateEmotion(input);
    return generateReply(input);
}

QString StellaCore::generateReply(const QString& input) {
    QString s = input.toLower();
    if (s.contains("joke")) 
        return m_jokes[QRandomGenerator::global()->bounded(m_jokes.size())];
    
    if (s.contains("task") || s.contains("plan") || s.contains("schedule"))
        return "Sure! Tell me your tasks for today.";
    
    if (s.contains("how are you"))
        return "I'm sparkling brightly today! How about you? ✨";
    
    return "I understand... Tell me more. I'm always here for you ✨";
}

Emotion StellaCore::getEmotion() const { 
    return m_emotion; 
}
