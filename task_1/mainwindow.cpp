#include "mainwindow.h"
#include <QMessageBox>
#include "state.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    Government state_1 = {250000, 300000.2, 'b', false, "Belarus", {0, 10, 25}};

    Government state_2;
    state_2.population = 360000;
    state_2.GDP = 51242.89;
    state_2.first_letter = 'j';
    state_2.in_war = false;
    strcpy(state_2.name, "Japan");
    state_2.type_taxes[0] = 50;
    state_2.type_taxes[1] = 25;
    state_2.type_taxes[2] = 3;

    QString out_put_1 = createStateString(state_1);
    QString out_put_2 = createStateString(state_2);

    ui->resultLineEdit->setText(out_put_1);
    ui->explicitEdit->setText(out_put_2);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::AddHelper);
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::CheckInt(QString input) {
    bool ok;
    input.toInt(&ok);
    return ok;
}

bool MainWindow::CheckDouble(QString input) {
    bool ok;
    input.toDouble(&ok);
    return ok;
}

QString MainWindow::createStateString(const Government& state) {
    return QString("%1|%2|%3|%4|%5|%6,%7,%8")
        .arg(state.population)
        .arg(state.GDP, 0, 'f', 2)
        .arg(state.first_letter)
        .arg(state.in_war ? "1" : "0")
        .arg(state.name)
        .arg(state.type_taxes[0])
        .arg(state.type_taxes[1])
        .arg(state.type_taxes[2]);
}

QString MainWindow::createPointerStateString(const Government* state) {
    return QString("%1|%2|%3|%4|%5|%6,%7,%8")
        .arg(state->population)
        .arg(state->GDP, 0, 'f', 2)
        .arg(state->first_letter)
        .arg(state->in_war ? "1" : "0")
        .arg(state->name)
        .arg(state->type_taxes[0])
        .arg(state->type_taxes[1])
        .arg(state->type_taxes[2]);
}

QString MainWindow::createRefStateString(Government& state) {
    return QString("%1|%2|%3|%4|%5|%6,%7,%8")
        .arg(state.population)
        .arg(state.GDP, 0, 'f', 2)
        .arg(state.first_letter)
        .arg(state.in_war ? "1" : "0")
        .arg(state.name)
        .arg(state.type_taxes[0])
        .arg(state.type_taxes[1])
        .arg(state.type_taxes[2]);
}

void MainWindow::AddHelper() {
    QString population_input = ui->populationEdit->text();
    QString gdp_input = ui->GDPEdit->text();
    QString first_letter_input = ui->firstLetterEdit->text();
    QString war_input = ui->warEdit->text();
    QString name_input = ui->nameEdit->text();
    QString first_tax_input = ui->firstTaxEdit->text();
    QString second_tax_input = ui->secondTexEdit->text();
    QString third_tax_input = ui->thirdTaxEdit->text();

    if (!CheckInt(population_input) || !CheckDouble(gdp_input) ||
        !CheckInt(first_tax_input) || !CheckInt(second_tax_input) ||
        !CheckInt(third_tax_input) || name_input.isEmpty() ||
        name_input.length() > 19) {
        QMessageBox::warning(this, "Input Error",
                             "Check input with int and double type and "
                             "name_input consist of 19 symbols or less",
                             QMessageBox::Ok);
    } else {
        int population = population_input.toInt();
        double gdp = gdp_input.toDouble();
        char first_letter = first_letter_input.isEmpty()
                                ? '\0'
                                : first_letter_input[0].toLatin1();

        bool in_war = war_input.isEmpty() ? 0 : 1;

        QByteArray byte_array = name_input.toUtf8();
        char name[20];
        strncpy(name, byte_array.constData(), 19);
        name[19] = '\0';

        int type_taxes[3] = {first_tax_input.toInt(), second_tax_input.toInt(),
                             third_tax_input.toInt()};

        if (population < 0 || gdp < 0 || name[0] == '\0' || type_taxes[0] < 0 ||
            type_taxes[1] < 0 || type_taxes[2] < 0) {
            QMessageBox::warning(this, "Input Error", "uncorrect some value",
                                 QMessageBox::Ok);
            ui->populationEdit->clear();
            ui->GDPEdit->clear();
            ui->firstLetterEdit->clear();
            ui->warEdit->clear();
            ui->nameEdit->clear();
            ui->firstTaxEdit->clear();
            ui->secondTexEdit->clear();
            ui->thirdTaxEdit->clear();
        }

        Government state_4 = {population, gdp, first_letter, in_war, {}, {}};

        strncpy(state_4.name, name, 20);
        state_4.type_taxes[0] = type_taxes[0];
        state_4.type_taxes[1] = type_taxes[1];
        state_4.type_taxes[2] = type_taxes[2];

        Government state_3;
        Government* ptr_state = &state_3;

        ptr_state->population = population;
        ptr_state->GDP = gdp;
        ptr_state->first_letter = first_letter;
        ptr_state->in_war = in_war;
        strncpy(ptr_state->name, name, 20);
        ptr_state->type_taxes[0] = type_taxes[0];
        ptr_state->type_taxes[1] = type_taxes[1];
        ptr_state->type_taxes[2] = type_taxes[2];

        Government state_5;
        Government& ref_state = state_5;
        ref_state.population = population;
        ref_state.GDP = gdp;
        ref_state.first_letter = first_letter;
        ref_state.in_war = in_war;
        strncpy(ref_state.name, name, 20);
        ref_state.type_taxes[0] = type_taxes[0];
        ref_state.type_taxes[1] = type_taxes[1];
        ref_state.type_taxes[2] = type_taxes[2];

        QString out_put_3 = createPointerStateString(ptr_state);
        QString out_put_4 = createStateString(state_4);
        QString out_put_5 = createRefStateString(ref_state);

        ui->pointerEdit->setText(out_put_3);
        ui->userEdit->setText(out_put_4);
        ui->refEdit->setText(out_put_5);
    }
    ui->populationEdit->clear();
    ui->GDPEdit->clear();
    ui->firstLetterEdit->clear();
    ui->warEdit->clear();
    ui->nameEdit->clear();
    ui->firstTaxEdit->clear();
    ui->secondTexEdit->clear();
    ui->thirdTaxEdit->clear();
}
