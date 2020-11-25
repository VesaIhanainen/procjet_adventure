#include "CharacterCreator.h"
#include "./ui_CharacterCreator.h"
#include <iostream>
#include <stdlib.h>
CharacterCreator::CharacterCreator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CharacterCreator)
{
    ui->setupUi(this);
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(on_generateButton_clicked()));
    connect(this, &CharacterCreator::valueChanged, this, &CharacterCreator::setValue);

}

CharacterCreator::~CharacterCreator()
{
    delete ui;
}


void CharacterCreator::on_generateButton_clicked()
{
    player.Str = int(rand()% 13 + 5);
    emit valueChanged(Ability::Str);
    player.Dex = int(rand()% 13 + 5);;
    emit valueChanged(Ability::Dex);
    player.Con = int(rand()% 13 + 5);;
    emit valueChanged(Ability::Con);
    player.Wis = int(rand()% 13 + 5);;
    emit valueChanged(Ability::Wis);
    player.Int = int(rand()% 13 + 5);;
    emit valueChanged(Ability::Int);
    player.Cha = int(rand()% 13 + 5);;
    emit valueChanged(Ability::Cha);
}

void CharacterCreator::setValue(Ability changedAbility)
{
    switch(changedAbility){
        case Ability::Str : ui->strScore->setNum(player.Str);
        case Ability::Dex : ui->dexScore->setNum(player.Dex);
        case Ability::Con : ui->conScore->setNum(player.Con);
        case Ability::Wis : ui->wisScore->setNum(player.Wis);
        case Ability::Int : ui->intScore->setNum(player.Int);
        case Ability::Cha : ui->chaScore->setNum(player.Cha);
    }
 }
