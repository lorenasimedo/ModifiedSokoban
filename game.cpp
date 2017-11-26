#include "game.h"
#include <QQmlEngine>
#include<QQmlComponent>
#include<QQmlProperty>
#include <QObject>
#include <QString>

Game::Game(QObject *parent) : QObject(parent)
{
    QQmlEngine engine;
    QQmlComponent component(&engine, "GameView.qml");
    game_view = component.create();
    game_canvas = game_view->findChild<QObject*>("gameCanvas");
}

void Game::createBoard() {
    //Qml GameView properties
    int gameCanvas_numOfRows = QQmlProperty::read(game_canvas, "numOfRows").toInt();
    int gameCanvas_numOfColumns = QQmlProperty::read(game_canvas, "numOfColumns").toInt();
    int gameView_currentLevel = QQmlProperty::read(game_view, "currentLevel").toInt();
    //QStringList gameView_levels = QQmlProperty::read(game_view, "levels").toStringList();
    QVariant returnedValue;
    int arguments[2];

    //board = new Array(gameCanvas.numOfRows);
    int **board = new int*[gameCanvas_numOfRows];
    int numOfGoals = 0;
    int numOfTreasures = 0;


    for (int row = 0; row <  gameCanvas_numOfRows; ++row) {
        //board[row] = new Array(gameCanvas.numOfColumns);
        board[row] = new int[gameCanvas_numOfColumns];
        for (int column = 0; column < gameCanvas_numOfColumns; ++column) {
            // 0: outside, 1: inside, 2: border, 3: goal, 4: object, 5: man, 6: object on goal, 7: man on goal

            arguments[0]=gameView_currentLevel;
            arguments[1]=row;
            QMetaObject::invokeMethod(game_view, "retornaLevelsPosicao",
                Q_RETURN_ARG(QVariant, returnedValue),
                Q_ARG(int*, arguments));

            QChar boardElement = (column < returnedValue.toString().size()) ? returnedValue.toString().at(column) : ' ';
            if (boardElement==' ') {
                    board[row][column] = 1;
            }else if(boardElement=='#'){
                    board[row][column] = 2;
            }else if(boardElement=='.'){
                board[row][column] = 3;
                ++numOfGoals;
            }else if(boardElement=='$'){
                board[row][column] = 4;
            }else if(boardElement=='@'){
                board[row][column] = 5;
            }else if(boardElement=='*'){
                board[row][column] = 6;
                ++numOfGoals;
                ++numOfTreasures;
            }else if(boardElement=='+'){
                board[row][column] = 7;
                ++numOfGoals;
            }else{
                board[row][column] = 0;
            }
        }
    }
    // create outside area
    // FIXME: find a better algorithm for this
    for (int row = 0; row < gameCanvas_numOfRows; ++row) {
        for (int column = 0; column < gameCanvas_numOfColumns && board[row][column] == 1; ++column) {
            board[row][column] = 0;
        }
        for (int column = gameCanvas_numOfColumns-1; column >= 0 && board[row][column] == 1; --column) {
            board[row][column] = 0;
        }
    }
    for (int column = 0; column < gameCanvas_numOfColumns; ++column) {
        for (int row = 0; row < gameCanvas_numOfRows && board[row][column] < 2; ++row) {
            board[row][column] = 0;
        }
        for (int row = gameCanvas_numOfRows-1; row >= 0 && board[row][column] < 2; --row) {
            board[row][column] = 0;
        }
    }
}
