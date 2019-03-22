#include "myqswitch.h"


#include <QDebug>
#include <QObject>


MyQSwitch::MyQSwitch(QWidget *parent) :
    QWidget(parent),
    m_heightNum(16),
    m_isChecked(false),
    m_isDisable(false),
    m_radiusNum(1),
    m_timeNum(10),
    m_nMargin(1),
    m_bgColor(Qt::black),
    m_unCheckedBgColor(190, 190, 190),
    m_unCheckedWrapBgColor(190, 190, 190),
    m_checkedBgColor(0, 150, 136),
    m_checkedWrapBgColor(0, 150, 136),
    m_disableBgColor(230, 230, 230),
    m_disableWrapBgColor(230, 230, 230)
{
    setCursor(Qt::PointingHandCursor);


    // 连接信号槽
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));



}

void MyQSwitch::setBgColor(QColor color)
{
    m_bgColor = color;

}

void MyQSwitch::setUnCheckedBgColor(QColor color)
{
    m_unCheckedBgColor = color;

}

void MyQSwitch::setUnCheckedWrapBgColor(QColor color)
{
    m_unCheckedWrapBgColor = color;

}

void MyQSwitch::setCheckedBgColor(QColor color)
{
    m_checkedBgColor = color;
}

void MyQSwitch::setCheckedWrapBgColor(QColor color)
{
    m_checkedWrapBgColor = color;
}

void MyQSwitch::setDisableBgColor(QColor color)
{
    m_disableBgColor = color;
}

void MyQSwitch::setDisableWrapBgColor(QColor color)
{
    m_disableWrapBgColor = color;

}

void MyQSwitch::setRadius(int radiusNum)
{
    m_radiusNum = radiusNum;
}

void MyQSwitch::setHeight(int heightNum)
{
    m_heightNum = heightNum;
}



void MyQSwitch::setToggleCdtion(bool isChecked)
{

    m_isChecked = isChecked;
    m_timer.start(m_timeNum);
}

void MyQSwitch::setDisableSwitch(bool isDisable)
{
    m_isDisable = isDisable;
}

void MyQSwitch::setTimeNum(int timeNum)
{
    m_timeNum = timeNum;
}

void MyQSwitch::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    qreal opacityNum;
    QPainterPath path;
    // 外层的背景
    QColor wrapBgColor;
    // 圆圈的背景
    QColor mainBgColor;

    painter.setBrush(m_bgColor);
    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing);

    if (!m_isDisable) {
        if ( m_isChecked ) {

            wrapBgColor = m_checkedWrapBgColor;
            mainBgColor = m_checkedBgColor;

            opacityNum = 0.6;

            setCursor(Qt::PointingHandCursor);
        } else {

            wrapBgColor = m_unCheckedWrapBgColor;
            mainBgColor = m_unCheckedBgColor;

            opacityNum = 0.8;

            setCursor(Qt::PointingHandCursor);
        }
    } else {

        wrapBgColor = m_disableWrapBgColor;
        mainBgColor = m_disableBgColor;

        opacityNum = 0.26;

        setCursor(Qt::ForbiddenCursor);
    }


    // 绘制大椭圆
    painter.setBrush(wrapBgColor);
    painter.setOpacity(opacityNum);
    path.addRoundedRect(QRectF(0,0,
                               width(),
                               height()),
                        height() / 2, height() / 2);
    painter.drawPath(path.simplified());


    // 绘制小椭圆
    painter.setBrush(mainBgColor);
    painter.setOpacity(1.0);
    painter.drawEllipse(QRectF(m_nMargin,0,
                               height(), height()));


}

void MyQSwitch::mousePressEvent(QMouseEvent *event)
{
    if (isEnabled()) {
        if(!m_isDisable){
            if (event->buttons() & Qt::LeftButton) {
                event->accept();
            } else {
                event->ignore();
            }
        }

    }
}

void MyQSwitch::mouseReleaseEvent(QMouseEvent *event)
{
    if (!m_isDisable) {
        if (m_isChecked) {
            event->accept();
            m_isChecked = false;

        } else {
            m_isChecked = true;
            event->ignore();
        }

        emit toggled(m_isChecked);
        m_timer.start(m_timeNum);
    }




}

void MyQSwitch::onTimeout()
{
    if (m_isChecked) {
        m_nMargin += 1;
        if (m_nMargin == width()-height()) {
            m_timer.stop();
        }
    } else {
        m_nMargin -= 1;
        if (m_nMargin == 0) {
            m_timer.stop();
        }
    }
    update();

}

void MyQSwitch::resizeEvent(QResizeEvent *event)
{

    QWidget::resizeEvent(event);
}
