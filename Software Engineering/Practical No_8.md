> **Name** : Darshan Bagade  **Roll No.** : 44

# Practical No. 8 — COCOMO Cost & Effort Estimation

**Course:** LAB: Software Engineering (23CT1704)
**Case Study:** Extra-Curricular Event Tracking System (ECETS)

## Aim
To write a program to estimate the cost and effort of a software project using the
COCOMO (Constructive Cost Model) technique for the given case study.

## Code 
```
# COCOMO (Basic) Cost and Effort Estimation
# Case Study: Extra-Curricular Event Tracking System

def basic_cocomo(kloc, mode="semi-detached"):
    coeffs = {
        "organic":       (2.4, 1.05, 2.5, 0.38),
        "semi-detached": (3.0, 1.12, 2.5, 0.35),
        "embedded":      (3.6, 1.20, 2.5, 0.32),
    }
    a, b, c, d = coeffs[mode]

    effort = a * (kloc ** b)      # Person-Months
    time   = c * (effort ** d)    # Months
    staff  = effort / time        # Average team size

    return effort, time, staff


if __name__ == "__main__":
    kloc = 20                 # Estimated size of Extra-Curricular
                               # Event Tracking System
    mode = "semi-detached"    # Medium complexity, mixed-experience team
    cost_per_pm = 60000       # Average cost per Person-Month (INR)

    effort, time, staff = basic_cocomo(kloc, mode)
    cost = effort * cost_per_pm

    print("Project           : Extra-Curricular Event Tracking System")
    print("Mode              :", mode)
    print("Estimated Size    :", kloc, "KLOC")
    print("Effort            : %.2f Person-Months" % effort)
    print("Development Time  : %.2f Months" % time)
    print("Average Staff     : %.2f People" % staff)
    print("Estimated Cost    : Rs. %.2f" % cost)
```

## Output
```
Project           : Extra-Curricular Event Tracking System
Mode              : semi-detached
Estimated Size    : 20 KLOC
Effort            : 85.96 Person-Months
Development Time  : 11.88 Months
Average Staff     : 7.23 People
Estimated Cost    : Rs. 5157344.00
```
