#ifndef STELLACORE_H
#define STELLACORE_H

#include <QObject>
#include <QString>
#include <QStringList>

enum class Emotion { Calm, Happy, Playful, Upset };

class StellaCore : public QObject {
    Q_OBJECT
public:
    explicit StellaCore(QObject* parent = nullptr);
    
    QString getGreeting();
    QString processInput(const QString& input);
    Emotion getEmotion() const;

private:
    void updateEmotion(const QString& input);
    QString generateReply(const QString& input);

    Emotion m_emotion = Emotion::Calm;
    QStringList m_jokes;
};

#endif // STELLACORE_H
