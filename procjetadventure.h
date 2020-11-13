#ifndef PROCJETADVENTURE_H
#define PROCJETADVENTURE_H

#include <QMainWindow>
#include "character.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class ProcjetAdventure; }
QT_END_NAMESPACE
enum Ability {Str=0, Dex, Con, Wis, Int, Cha};
class ProcjetAdventure : public QMainWindow
{
    Q_OBJECT

public:
    ProcjetAdventure(QWidget *parent = nullptr);
    ~ProcjetAdventure();
public slots:
    void on_generateButton_clicked();
    void setValue(Ability);
signals:
    void valueChanged(Ability);
private:
    Ui::ProcjetAdventure *ui;
    Character player;    
};
#endif // PROCJETADVENTURE_H
