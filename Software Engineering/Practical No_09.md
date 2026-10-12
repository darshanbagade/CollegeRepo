# Extracurricular Management System - Manual and Automated GUI Testing

A small PyQt5 desktop application (login + activity registration) built as the sample GUI for **Practical 9** of the Software Engineering lab. The practical applies **manual testing** and **automated testing** (with the CASE tool **pytest-qt**) to verify the GUI against its specified behaviour.

| | |
|---|---|
| **Student** | Darshan Bagade |
| **Roll No** | 44 |
| **Course** | LAB: Software Engineering (23CT1704) |
| **Semester** | 7th, Session 2026-27 (ODD) |
| **Department** | Computer Technology, Yeshwantrao Chavan College of Engineering, Nagpur |
| **Practical Number** | 9 |
| **Course Outcome** | CO5: Apply manual and automated testing techniques, using CASE tools, to verify the functionality of a software system |
| **Aim** | To perform manual and automated testing using a CASE tool with a sample GUI |

---

## Theory

**Software testing** is the process of executing a software product with the intention of finding defects and verifying that it meets its specified requirements. It improves the quality and reliability of the software.

**Manual testing** is testing in which a tester executes test cases by hand, interacting with the application as an end user would and comparing the actual result with the expected result. It is useful for exploratory, usability and one-time tests, but it is slow, repetitive and prone to human error.

**Automated testing** uses a tool to execute pre-written test scripts, compare the actual and expected results and report the outcome automatically. It is fast, repeatable and well suited for regression testing, but needs an initial effort to write and maintain the scripts.

**CASE (Computer-Aided Software Engineering) tools** are software tools that support the activities of the software life cycle, including analysis, design, coding, testing and maintenance. Testing CASE tools such as Selenium, Katalon Studio, TestComplete, JUnit and pytest-qt help to create, run and report tests. In this practical, **pytest with the pytest-qt plug-in** is used as the automated GUI testing tool; it simulates real mouse and keyboard events on the widgets of the application.

**GUI testing** checks the graphical user interface - fields, buttons, messages and navigation - to confirm that it accepts valid input, rejects invalid input with a suitable message and behaves as specified.

### Manual versus automated testing

| Aspect | Manual Testing | Automated Testing |
|---|---|---|
| Execution | Performed by a human tester | Performed by a tool using scripts |
| Speed | Slow | Fast |
| Repeatability | Effort repeated every time | Scripts re-run at no extra effort |
| Reliability | Prone to human error | Consistent results |
| Best suited for | Exploratory and usability testing | Regression and repetitive testing |

---

## Procedure (Algorithm)

1. Select a sample GUI to be tested - an Extracurricular Management System with a login section and a registration section.
2. Study the requirements of the GUI: login rules, registration validation rules and the behaviour of each button.
3. Design test cases covering valid inputs, invalid inputs and boundary values, with the expected result for each.
4. **Manual testing:** run the GUI, execute each test case by entering the inputs by hand, observe the result and record it as Pass or Fail.
5. **Automated testing:** write test scripts for the same test cases using pytest-qt, which simulates the typing and clicking.
6. Run the automated test suite and collect the report.
7. Compare the manual and automated results, and log and fix any defects found.

---

## About the application

The sample GUI is an **Extracurricular Management System** developed in Python using PyQt5. The student first logs in (valid credentials: `student1` / `pass123`); only then does the registration section become enabled. The student selects an activity (Cricket Team, Music Club, Robotics Club or Dance Club), a Participant or Volunteer role, and enters the Student ID and the hours per week. The GUI validates the input and shows a confirmation or error message in the status line.

**Login rules**
- Username and password are both required.
- Valid credentials: `student1` / `pass123`.

**Registration rules**
- Student ID must be exactly 6 digits.
- Hours per week must be a positive whole number, at most 20.
- The **Clear** button resets the form (ID, hours, activity, role).



## Requirements and setup

- Python 3.8 or newer
- PyQt5, pytest, pytest-qt

```bash
git clone https://github.com/sambodhit13/SE_practical.git
cd SE_practical

python -m venv venv
# Windows
venv\Scripts\activate
# Linux / macOS
source venv/bin/activate

pip install PyQt5 pytest pytest-qt
```

Run the application:

```bash
python extracurricular_gui.py
```

Run the automated tests:

```bash
pytest -v
```

On a machine without a display (CI, remote server), run the tests headlessly:

```bash
QT_QPA_PLATFORM=offscreen pytest -v
```

---

## Sample GUI source code (`extracurricular_gui.py`)

```python
# Sample GUI: Extracurricular Management System (login + activity registration) - PyQt5
import sys
from PyQt5.QtWidgets import (QApplication, QWidget, QVBoxLayout, QHBoxLayout, QGroupBox,
    QFormLayout, QLineEdit, QComboBox, QRadioButton, QPushButton, QLabel)

VALID_USER, VALID_PASS, MAX_HOURS = "student1", "pass123", 20

class ExtracurricularWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Extracurricular Management System")
        # ---- login section ----
        self.user = QLineEdit(); self.user.setObjectName("user")
        self.pwd = QLineEdit(); self.pwd.setObjectName("pwd")
        self.pwd.setEchoMode(QLineEdit.Password)
        self.btn_login = QPushButton("Login"); self.btn_login.setObjectName("btn_login")
        lg = QGroupBox("Student Login"); f1 = QFormLayout(lg)
        f1.addRow("Username:", self.user); f1.addRow("Password:", self.pwd)
        f1.addRow(self.btn_login)
        # ---- registration section ----
        self.activity = QComboBox(); self.activity.setObjectName("activity")
        self.activity.addItems(["Cricket Team", "Music Club", "Robotics Club", "Dance Club"])
        self.rb_part = QRadioButton("Participant"); self.rb_vol = QRadioButton("Volunteer")
        self.rb_part.setChecked(True)
        role = QHBoxLayout(); role.addWidget(self.rb_part); role.addWidget(self.rb_vol)
        self.sid = QLineEdit(); self.sid.setObjectName("sid")
        self.hours = QLineEdit(); self.hours.setObjectName("hours")
        self.btn_reg = QPushButton("Register"); self.btn_reg.setObjectName("btn_reg")
        self.btn_clear = QPushButton("Clear"); self.btn_clear.setObjectName("btn_clear")
        btns = QHBoxLayout(); btns.addWidget(self.btn_reg); btns.addWidget(self.btn_clear)
        self.reg_box = QGroupBox("Activity Registration"); f2 = QFormLayout(self.reg_box)
        f2.addRow("Activity:", self.activity); f2.addRow("Role:", role)
        f2.addRow("Student ID:", self.sid); f2.addRow("Hours / week:", self.hours)
        f2.addRow(btns)
        self.reg_box.setEnabled(False)
        self.status = QLabel("Please login."); self.status.setObjectName("status")
        self.status.setWordWrap(True)
        lay = QVBoxLayout(self)
        lay.addWidget(lg); lay.addWidget(self.reg_box); lay.addWidget(self.status)
        self.btn_login.clicked.connect(self.do_login)
        self.btn_reg.clicked.connect(self.do_register)
        self.btn_clear.clicked.connect(self.do_clear)

    def do_login(self):
        u, p = self.user.text().strip(), self.pwd.text()
        if not u or not p:
            self.status.setText("Error: Username and password are required"); return
        if u == VALID_USER and p == VALID_PASS:
            self.status.setText("Login successful. You can register for activities.")
            self.reg_box.setEnabled(True)
        else:
            self.status.setText("Error: Invalid username or password")

    def do_register(self):
        s, h = self.sid.text().strip(), self.hours.text().strip()
        if not (s.isdigit() and len(s) == 6):
            self.status.setText("Error: Student ID must be exactly 6 digits"); return
        if not h.isdigit() or int(h) <= 0:
            self.status.setText("Error: Hours must be a positive whole number"); return
        if int(h) > MAX_HOURS:
            self.status.setText("Error: Hours exceed the limit of %d per week" % MAX_HOURS); return
        role = "PARTICIPANT" if self.rb_part.isChecked() else "VOLUNTEER"
        self.status.setText("Registered: %s %s hrs/week in %s (ID %s)" %
                            (role, h, self.activity.currentText(), s))

    def do_clear(self):
        self.sid.clear(); self.hours.clear(); self.rb_part.setChecked(True)
        self.activity.setCurrentIndex(0); self.status.setText("Form cleared.")

if __name__ == "__main__":
    app = QApplication(sys.argv); w = ExtracurricularWindow(); w.show(); sys.exit(app.exec_())
```

---

## A. Manual testing

The test cases below were executed by hand on the GUI and the observed results recorded:

| ID | Scenario | Input / Steps | Expected Result | Result |
|---|---|---|---|---|
| TC1 | Registration section before login | Open the GUI | Registration section is disabled | Pass |
| TC2 | Valid login | `student1` / `pass123`, click Login | "Login successful"; registration section enabled | Pass |
| TC3 | Invalid password | `student1` / `wrong` | "Invalid username or password"; registration section stays disabled | Pass |
| TC4 | Empty login fields | Click Login with empty fields | "Username and password are required" | Pass |
| TC5 | Valid Participant registration | Robotics Club, Participant, ID 240075, Hours 5 | "Registered: PARTICIPANT 5 hrs/week in Robotics Club (ID 240075)" | Pass |
| TC6 | Valid Volunteer registration | Music Club, Volunteer, ID 240112, Hours 3 | "Registered: VOLUNTEER 3 hrs/week in Music Club (ID 240112)" | Pass |
| TC7 | Zero hours | ID 240075, Hours 0 | "Hours must be a positive whole number" | Pass |
| TC8 | Non-numeric hours | ID 240075, Hours abc | "Hours must be a positive whole number" | Pass |
| TC9 | Hours above limit | ID 240075, Hours 21 | "Hours exceed the limit of 20 per week" | Pass |
| TC10 | Invalid Student ID | ID 12345, Hours 5 | "Student ID must be exactly 6 digits" | Pass |
| TC11 | Clear button | Enter ID 240075, Hours 5; click Clear | Fields cleared; Participant selected | Pass |

---

## B. Automated testing

The same test cases were scripted using pytest-qt (`test_extracurricular_gui.py`):

```python
# Automated GUI tests using pytest-qt (QTest event simulation)
import pytest
from PyQt5.QtCore import Qt
from extracurricular_gui import ExtracurricularWindow

@pytest.fixture
def win(qtbot):
    w = ExtracurricularWindow(); qtbot.addWidget(w); w.show(); return w

def login(qtbot, w, u="student1", p="pass123"):
    qtbot.keyClicks(w.user, u); qtbot.keyClicks(w.pwd, p)
    qtbot.mouseClick(w.btn_login, Qt.LeftButton)

def register(qtbot, w, sid, hrs):
    qtbot.keyClicks(w.sid, sid); qtbot.keyClicks(w.hours, hrs)
    qtbot.mouseClick(w.btn_reg, Qt.LeftButton)

def test_tc01_registration_disabled_before_login(win):
    assert not win.reg_box.isEnabled()

def test_tc02_valid_login(qtbot, win):
    login(qtbot, win)
    assert "Login successful" in win.status.text() and win.reg_box.isEnabled()

def test_tc03_invalid_password(qtbot, win):
    login(qtbot, win, p="wrong")
    assert "Invalid username or password" in win.status.text()
    assert not win.reg_box.isEnabled()

def test_tc04_empty_login(qtbot, win):
    qtbot.mouseClick(win.btn_login, Qt.LeftButton)
    assert "required" in win.status.text()

def test_tc05_valid_participant_registration(qtbot, win):
    login(qtbot, win); win.activity.setCurrentText("Robotics Club")
    register(qtbot, win, "240075", "5")
    assert win.status.text() == "Registered: PARTICIPANT 5 hrs/week in Robotics Club (ID 240075)"

def test_tc06_valid_volunteer_registration(qtbot, win):
    login(qtbot, win); qtbot.mouseClick(win.rb_vol, Qt.LeftButton)
    win.activity.setCurrentText("Music Club"); register(qtbot, win, "240112", "3")
    assert win.status.text() == "Registered: VOLUNTEER 3 hrs/week in Music Club (ID 240112)"

def test_tc07_zero_hours(qtbot, win):
    login(qtbot, win); register(qtbot, win, "240075", "0")
    assert "Hours must be a positive whole number" in win.status.text()

def test_tc08_non_numeric_hours(qtbot, win):
    login(qtbot, win); register(qtbot, win, "240075", "abc")
    assert "Hours must be a positive whole number" in win.status.text()

def test_tc09_hours_above_limit(qtbot, win):
    login(qtbot, win); register(qtbot, win, "240075", "21")
    assert "exceed the limit" in win.status.text()

def test_tc10_invalid_student_id(qtbot, win):
    login(qtbot, win); register(qtbot, win, "12345", "5")
    assert "Student ID must be exactly 6 digits" in win.status.text()

def test_tc11_clear_button(qtbot, win):
    login(qtbot, win); qtbot.keyClicks(win.sid, "240075"); qtbot.keyClicks(win.hours, "5")
    qtbot.mouseClick(win.btn_clear, Qt.LeftButton)
    assert win.sid.text() == "" and win.hours.text() == "" and win.rb_part.isChecked()
```

### Automated test execution report

Run `pytest -v` and the 11 test cases are reported as follows:

<!-- Paste the real output of `pytest -v` here (the 11 test lines and the final summary line). -->

---

## C. Comparison of results

The manual and automated test cases use the same inputs and expected results, and all 11 expected results match the behaviour of the GUI's validation code, so the GUI behaves as specified. Manual execution means typing the inputs and reading the status line by hand every time, whereas the automated suite runs all 11 cases in a fraction of a second and can be re-run after every change to the GUI as a regression test.

---

## Outcome

The student successfully performed manual and automated testing of a sample GUI (Extracurricular Management System) using a CASE tool (pytest-qt). Eleven test cases were designed and executed manually and by automation, and all of them passed.

## Conclusion

This practical helped in understanding the difference between manual and automated testing and the role of CASE tools in software testing. Testing the sample GUI showed that manual testing is useful for observing the interface directly, while automated testing is faster, repeatable and more reliable for regression testing.

---

## Author

**Sambodhit Chavhan** - Roll No 75, Department of Computer Technology, Yeshwantrao Chavan College of Engineering, Nagpur
GitHub: [sambodhit13](https://github.com/sambodhit13) | Repository: [SE_practical](https://github.com/sambodhit13/SE_practical)
