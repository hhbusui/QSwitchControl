#ifndef MYQSWITCH_H
#define MYQSWITCH_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>

class MyQSwitch : public QWidget
{
    Q_OBJECT
public:
    explicit MyQSwitch(QWidget *parent = nullptr);

    // 设置颜色
    void setBgColor(QColor color);

    void setUnCheckedBgColor(QColor color);
    void setUnCheckedWrapBgColor(QColor color);

    void setCheckedBgColor(QColor color);
    void setCheckedWrapBgColor(QColor color);

    void setDisableBgColor(QColor color);
    void setDisableWrapBgColor(QColor color);

    // 状态
    // 设置圆角状态
    void setRadius(int radiusNum);
    // 设置宽高状态
    void setHeight(int heightNum);
    // 设置选中状态
    void setToggleCdtion(bool isChecked);
    // 设置是否禁用
    void setDisableSwitch(bool isDisable);
    // 设置过渡动画时间
    void setTimeNum(int timeNum);






signals:
    void toggled(bool checkCdtion);

public slots:
    void onTimeout();


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);


private:
    bool m_isChecked;
    bool m_isDisable;
    // 颜色
    QColor m_bgColor;

    QColor m_unCheckedBgColor;
    QColor m_unCheckedWrapBgColor;

    QColor m_checkedBgColor;
    QColor m_checkedWrapBgColor;

    QColor m_disableBgColor;
    QColor m_disableWrapBgColor;

    qreal m_radiusNum;
    qreal m_heightNum;
    // 设置xy坐标
    qreal m_nX;
    qreal m_nY;
    qreal m_nMargin;
    int m_timeNum;

    QTimer m_timer;





};

#endif // MYQSWITCH_H
