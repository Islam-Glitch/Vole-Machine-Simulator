#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QScreen>
#include <QScrollArea>
#include <QVBoxLayout>
#include "VoleMachine.h"

class VoleMachineGUI : public QWidget {
    Q_OBJECT

private:
    VoleMachine voleMachine;

    QScrollArea* memoryScrollArea;
    QLabel* memoryContentLabel;
    QLabel* registerLabel;
    QLabel* instructionLabel;
    QLabel* counterLabel;
    QLabel* decodedContentLabel;

public:
    VoleMachineGUI(QWidget* parent = nullptr) : QWidget(parent) {
        // Create labels to display information
        memoryContentLabel = new QLabel("Memory Content: " + QString::fromStdString(voleMachine.machineMemory.getContentAsString()));
        registerLabel = new QLabel("Register Content: " + QString::fromStdString(voleMachine.machineRegister.getContentAsString()));
        instructionLabel = new QLabel("Instruction: ");
        counterLabel = new QLabel("Counter: ");
        decodedContentLabel = new QLabel("Decoded Content: ");

        // Set boxes around the content labels
        memoryContentLabel->setFrameStyle(QFrame::Box);
        registerLabel->setFrameStyle(QFrame::Box);

        // Create buttons
        QPushButton* loadInstructionButton = new QPushButton("Load Instruction");
        QPushButton* clearMemoryButton = new QPushButton("Clear Memory");
        QPushButton* clearRegisterButton = new QPushButton("Clear Register");
        QPushButton* fetchButton = new QPushButton("Fetch");
        QPushButton* decodeButton = new QPushButton("Decode");
        QPushButton* executeButton = new QPushButton("Execute");
        QPushButton* runOneCycleButton = new QPushButton("Run One Cycle");

        // Connect buttons to slots (functions)
        connect(loadInstructionButton, &QPushButton::clicked, this, &VoleMachineGUI::loadInstruction);
        connect(clearMemoryButton, &QPushButton::clicked, this, &VoleMachineGUI::clearMemory);
        connect(clearRegisterButton, &QPushButton::clicked, this, &VoleMachineGUI::clearRegister);
        connect(fetchButton, &QPushButton::clicked, this, &VoleMachineGUI::fetch);
        connect(decodeButton, &QPushButton::clicked, this, &VoleMachineGUI::decode);
        connect(executeButton, &QPushButton::clicked, this, &VoleMachineGUI::execute);
        connect(runOneCycleButton, &QPushButton::clicked, this, &VoleMachineGUI::runOneCycle);

        // Create layout
        QGridLayout* mainLayout = new QGridLayout;

        // Get desktop size using QScreen
        QScreen *screen = QGuiApplication::primaryScreen();
        QRect desktopRect = screen->availableGeometry();
        int desktopWidth = desktopRect.width();
        int desktopHeight = desktopRect.height();

        // Set a fixed size for the main window
        setFixedSize(desktopWidth * 0.8, desktopHeight * 0.8);

        // Create scroll area for memory content
        memoryScrollArea = new QScrollArea;
        memoryScrollArea->setWidget(memoryContentLabel);
        memoryScrollArea->setWidgetResizable(true);

        // Add labels to the layout
        mainLayout->addWidget(memoryScrollArea, 0, 0, 1, 2);
        mainLayout->addWidget(registerLabel, 0, 2, 1, 2);
        mainLayout->addWidget(instructionLabel, 1, 0);
        mainLayout->addWidget(counterLabel, 1, 1);
        mainLayout->addWidget(decodedContentLabel, 1, 2, 1, 2);

        // Add buttons to the layout
        mainLayout->addWidget(loadInstructionButton, 2, 0);
        mainLayout->addWidget(clearMemoryButton, 2, 1);
        mainLayout->addWidget(clearRegisterButton, 2, 2);
        mainLayout->addWidget(fetchButton, 2, 3);
        mainLayout->addWidget(decodeButton, 3, 0);
        mainLayout->addWidget(executeButton, 3, 1);
        mainLayout->addWidget(runOneCycleButton, 3, 2, 1, 2);

        // Set the main layout for the widget
        setLayout(mainLayout);

        // Display initial content
        updateLabels();
    }

private slots:
    void loadInstruction() {
        QString filePath = QFileDialog::getOpenFileName(this, "Open Instruction File", "", "Text Files (*.txt);;All Files (*)");
        if (!filePath.isEmpty()) {
            voleMachine.machineMemory.load_instructions(filePath.toStdString());
            updateLabels();
        }
    }

    void clearMemory() {
        voleMachine.counter = 0;
        voleMachine.instruction = "0000";
        voleMachine.machineMemory.clearMemory();
        updateLabels();
    }

    void clearRegister() {
        voleMachine.machineRegister.clearRegister();
        updateLabels();
    }

    void fetch() {
        voleMachine.Fetch();
        updateLabels();
    }

    void decode() {
        QString decodedContent = QString::fromStdString(voleMachine.Decode());
        decodedContentLabel->setText("Decoded Content: " + decodedContent);
    }

    void execute() {
        voleMachine.Execute();
        updateLabels();
    }

    void runOneCycle() {
        voleMachine.runOneCycle();
        updateLabels();
    }

    void updateLabels() {
        memoryContentLabel->setText("Memory Content:\n" + QString::fromStdString(voleMachine.machineMemory.getContentAsString()));
        registerLabel->setText("Register Content:\n" + QString::fromStdString(voleMachine.machineRegister.getContentAsString()));
        instructionLabel->setText("Instruction: " + QString::fromStdString(voleMachine.instruction));
        counterLabel->setText("Counter: " + QString::fromStdString(VoleMachine::decimalToHexa(voleMachine.counter)));
        decodedContentLabel->clear();
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VoleMachineGUI mainWindow;
    mainWindow.show();

    return app.exec();
}

#include "main.moc"
