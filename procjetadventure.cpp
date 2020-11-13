#include "procjetadventure.h"
#include "./ui_procjetadventure.h"
#include <iostream>
#include <stdlib.h>
ProcjetAdventure::ProcjetAdventure(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProcjetAdventure)
{
    ui->setupUi(this);
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(on_generateButton_clicked()));
    connect(this, &ProcjetAdventure::valueChanged, this, &ProcjetAdventure::setValue);

}

ProcjetAdventure::~ProcjetAdventure()
{
    delete ui;
}


void ProcjetAdventure::on_generateButton_clicked()
{
    player.Str = int(rand()% 18 + 5);
    emit valueChanged(Ability::Str);
    player.Dex = int(rand()% 18 + 5);;
    emit valueChanged(Ability::Dex);
    player.Con = int(rand()% 18 + 5);;
    emit valueChanged(Ability::Con);
    player.Wis = int(rand()% 18 + 5);;
    emit valueChanged(Ability::Wis);
    player.Int = int(rand()% 18 + 5);;
    emit valueChanged(Ability::Int);
    player.Cha = int(rand()% 18 + 5);;
    emit valueChanged(Ability::Cha);
}

void ProcjetAdventure::setValue(Ability changedAbility)
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
