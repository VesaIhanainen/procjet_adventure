#ifndef PROCJETADVENTURE_H
#define PROCJETADVENTURE_H

#include <QMainWindow>
#include "character.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class CharacterCreator; }
QT_END_NAMESPACE
enum Ability {Str=0, Dex, Con, Wis, Int, Cha};
class CharacterCreator : public QMainWindow
{
    Q_OBJECT

public:
    CharacterCreator(QWidget *parent = nullptr);
    ~CharacterCreator();
public slots:
    void on_generateButton_clicked();
    void on_continueButton_clicked();
    void setValue(Ability);
    //void setName();
signals:
    void valueChanged(Ability);
    //void nameChanged();
private:
    Ui::CharacterCreator *ui;
    Character player;    
};
#endif // PROCJETADVENTURE_H
