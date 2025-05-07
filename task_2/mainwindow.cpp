#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->calculateButton, &QPushButton::clicked, this,
            &MainWindow::AddParagraph);
    connect(ui->addElemenButton, &QPushButton::clicked, this,
            &MainWindow::AddElementArray);
    connect(ui->createArrayButton, &QPushButton::clicked, this,
            &MainWindow::CreateArray);
    connect(ui->calculateArrayButton, &QPushButton::clicked, this,
            &MainWindow::CalculateArray);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::AddHelper);

    connect(ui->addSentenceButton, &QPushButton::clicked, this,
            &MainWindow::AddSentence);
}

MainWindow::~MainWindow() {
    delete ui;
    delete[] array;
}

bool MainWindow::CheckDouble(QString input) {
    bool ok;
    input.toDouble(&ok);
    return ok;
}

bool MainWindow::CheckInt(QString input) {
    bool ok;
    input.toInt(&ok);
    return ok;
}

void MainWindow::AddParagraph() {
    QString input = ui->inputEdit->toPlainText();

    QFile file("test.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Utf16);

        for (int i = 0; i < input.length(); ++i) {
            QChar ch = input.at(i);
            stream << ch;
        }

        file.close();
    }

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::Utf16);

        QString readText;
        QChar ch;

        if (!stream.atEnd()) {
            stream >> ch;
            if (ch != QChar(0xFEFF)) {
                readText += ch;
            }
        }

        while (!stream.atEnd()) {
            stream >> ch;
            readText += ch;
        }

        file.close();
        ui->outputEdit->setPlainText(readText);
    }

    ui->inputEdit->clear();
}

void MainWindow::AddElementArray() {
    QString input = ui->elemntEdit->text();
    if (!CheckDouble(input)) {
        QMessageBox::warning(this, "Input Error",
                             "check input with double type", QMessageBox::Ok);
    } else {
        if (number_of_element >= size) {
            QMessageBox::warning(this, "Input Error",
                                 "array consist all element", QMessageBox::Ok);
            return;
        }

        double element = input.toDouble();

        array[number_of_element] = element;

        number_of_element++;
    }
    ui->elemntEdit->clear();
}

void MainWindow::CalculateArray() {
    if (number_of_element < size) {
        QMessageBox::warning(this, "Input Error",
                             "array does not consist all element",
                             QMessageBox::Ok);
        return;
    }

    QFile file("test.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);


        for (int i = 0; i < size; ++i) {
            stream << array[i];
            if (i != size - 1) {
                stream << "=";
            }
        }

        file.close();

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Error",
                                  "Could not open file for reading",
                                  QMessageBox::Ok);
            return;
        }

        QTextStream new_stream(&file);
        QStringList elements;
        QString content = new_stream.readAll();

        elements = content.split('=');

        QString displayText = elements.join(' ');

        ui->arrayResultEdit->setText(displayText);

        file.close();

    } else {
        QMessageBox::critical(this, "Error", "Could not open file for writing",
                              QMessageBox::Ok);
    }
    ui->numberOfArrayEdit->clear();
}

void MainWindow::CreateArray() {
    QString input = ui->numberOfArrayEdit->text();
    if (!CheckInt(input)) {
        QMessageBox::warning(this, "Input Error", "check input with int type",
                             QMessageBox::Ok);
        ui->numberOfArrayEdit->clear();
    } else {
        size = input.toInt();
        if (size < 1) {
            QMessageBox::warning(this, "Input Error",
                                 "size need to be more than 0",
                                 QMessageBox::Ok);
            return;
        }
        delete[] array;
        array = new double[size];
        number_of_element = 0;
    }
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

        QFile file("struct.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append |

                      QIODevice::Text)) {
            QTextStream stream(&file);
            stream << "Population: " << state_4.population << "\n";
            stream << "GDP: " << state_4.GDP << "\n";
            stream << "First Letter: "
                   << (state_4.first_letter ? QString(state_4.first_letter)
                                            : "None")
                   << "\n";
            stream << "In War: " << (state_4.in_war ? "Yes" : "No") << "\n";
            stream << "Name: " << state_4.name << "\n";
            stream << "Taxes: " << state_4.type_taxes[0] << ", "
                   << state_4.type_taxes[1] << ", " << state_4.type_taxes[2]
                   << "\n";
            stream << "----------------------------\n";
            file.close();

            ReadAndDisplayStructures();


        } else {
            QMessageBox::critical(this, "Error",
                                  "Could not open file for writing",
                                  QMessageBox::Ok);
        }

        QFile new_file("new_struct.bin");
        if (new_file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            new_file.write(reinterpret_cast<char*>(&state_4),
                           sizeof(Government));
            new_file.close();


            if (!new_file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, "Error",
                                      "Could not open file for reading",
                                      QMessageBox::Ok);
                return;
            }

            QString output;
            Government state;

            while (new_file.read(reinterpret_cast<char*>(&state),
                                 sizeof(Government))) {
                output +=
                    QString("%1;%2;%3;%4;%5;%6;%7;%8\n")
                        .arg(state.population)
                        .arg(state.GDP)
                        .arg(state.first_letter ? QString(state.first_letter)
                                                : "None")
                        .arg(state.in_war ? "Yes" : "No")
                        .arg(state.name)
                        .arg(state.type_taxes[0])
                        .arg(state.type_taxes[1])
                        .arg(state.type_taxes[2]);
            }

            new_file.close();

            if (!output.isEmpty()) {
                ui->newstructEdit->setPlainText(output);
            } else {
                QMessageBox::information(this, "Info",
                                         "No structures found in file",
                                         QMessageBox::Ok);
            }


        } else {
            QMessageBox::critical(this, "Error",
                                  "Could not open file for writing",
                                  QMessageBox::Ok);
        }
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

void MainWindow::AddSentence() {
    QString input = ui->inputSentenceEdit->text().trimmed();

    if (input.isEmpty()) {
        QMessageBox::warning(this, "error", "line is empty", QMessageBox::Ok);
        return;
    }

    QFile file("Sentences.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << input << "\n";
        file.close();

        ui->inputSentenceEdit->clear();

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            QString allText = stream.readAll();
            file.close();

            ui->resultSentencesEdit->setPlainText(allText);
        } else {
            QMessageBox::critical(this, "error", "do not read file",
                                  QMessageBox::Ok);
        }


    } else {
        QMessageBox::critical(this, "error", "do not open file",
                              QMessageBox::Ok);
    }
}

void MainWindow::ReadAndDisplayStructures() {
    QFile file("struct.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open file for reading",
                              QMessageBox::Ok);
        return;
    }

    QTextStream stream(&file);
    QString output;
    Government currentState;
    bool readingStructure = false;

    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();

        if (line.startsWith("----------------------------")) {
            if (readingStructure) {
                output += QString("%1|%2|%3|%4|%5|%6,%7,%8\n")
                              .arg(currentState.population)
                              .arg(currentState.GDP)
                              .arg(currentState.first_letter
                                       ? QString(currentState.first_letter)
                                       : "None")
                              .arg(currentState.in_war ? "Yes" : "No")
                              .arg(currentState.name)
                              .arg(currentState.type_taxes[0])
                              .arg(currentState.type_taxes[1])
                              .arg(currentState.type_taxes[2]);
            }
            readingStructure = false;
            continue;
        }

        if (line.startsWith("Population:")) {
            currentState.population = line.section(':', 1).trimmed().toInt();
            readingStructure = true;
        } else if (line.startsWith("GDP:")) {
            currentState.GDP = line.section(':', 1).trimmed().toDouble();
        } else if (line.startsWith("First Letter:")) {
            QString letter = line.section(':', 1).trimmed();
            currentState.first_letter =
                (letter == "None") ? '\0' : letter.at(0).toLatin1();
        } else if (line.startsWith("In War:")) {
            currentState.in_war = (line.section(':', 1).trimmed() == "Yes");
        } else if (line.startsWith("Name:")) {
            QString name = line.section(':', 1).trimmed();
            strncpy(currentState.name, name.toUtf8().constData(), 19);
            currentState.name[19] = '\0';
        } else if (line.startsWith("Taxes:")) {
            QString taxesStr = line.section(':', 1).trimmed();
            QStringList taxes = taxesStr.split(',');
            if (taxes.size() == 3) {
                currentState.type_taxes[0] = taxes[0].trimmed().toInt();
                currentState.type_taxes[1] = taxes[1].trimmed().toInt();
                currentState.type_taxes[2] = taxes[2].trimmed().toInt();
            }
        }
    }

    file.close();

    if (!output.isEmpty()) {
        ui->structEdit->setPlainText(output);
    } else {
        QMessageBox::information(this, "Info", "No structures found in file",
                                 QMessageBox::Ok);
    }
}
