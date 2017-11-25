#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVariant>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);

signals:

private:
    QVariant boardItems; // list of floor, goal and border items on the field
    QVariant maxIndex = 0; // number of cells in the current level's field = gameCanvas.numOfColumns * gameCanvas.numOfRows
    QVariant board; // array containing the description of the current level's board
    QVariant numOfGoals = 0; // number of goal items (= number of objects)
    QVariant numOfTreasures = 0; // number of objects already on a goal item
    QVariant itemObjects; // list of object items on the field
    QVariant itemMan; // man item
    QVariant undoHistory; // list of moves of the man and whether the man pushed an object on each move
    QVariant undoHistoryStep; // number of the current step in the undo history

public slots:
};

#endif // GAME_H
