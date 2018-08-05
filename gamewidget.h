#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>

#include "mylabel.h"
#include "bgwidget.h"

namespace Ui {
class Widget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

    enum GestureDirect{
        LEFT,   //左
        RIGHT,  //右
        UP,     //上
        DOWN    //下
    };

    //随机生成标签
    void createLabel();
    //初始化游戏
    void initGame();
    //合并,并将合并成功与否的结果返回
    bool merge(MyLabel *temp,int row,int col);
    //是否能合并
    bool isMerge();
    //游戏结束
    bool gameOver();
    //保存当前游戏进度
    void saveGame();
    //释放资源
    void releaseRes();
    //关闭事件
    void closeEvent(QCloseEvent *event);
    //键盘事件
    void keyPressEvent(QKeyEvent *event);

private:
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();

    bool isMergeUp(int row,int col);
    bool isMergeDown(int row,int col);
    bool isMergeLeft(int row,int col);
    bool isMergeRight(int row,int col);

signals:
    //按键时触发该信号
    void GestureMove(GestureDirect direction);
    //改变分数
    void ScoreChange();

private slots:
    //设置分数
    void setScore();
    //移动
    void moveLabel(GestureDirect direction);
    //重新开始
    void on_bt_restart_clicked();

private:
    Ui::Widget *ui;
    int m_score;                    //当前得分
    int m_highScore;                //历史最高得分
    int m_labelCount;               //标签的数量
    MyLabel *labels[4][4];          //标签
    BGWidget * m_bgWidget;          //主游戏窗口
};

#endif // GAMEWIDGET_H
