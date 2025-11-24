# 📚 **LibraFlow -- Library Management System (C Language)**

LibraFlow is a beginner-friendly **Library Management System** written
entirely in **C language**.\
It allows librarians or users to **issue books**, **return books**,
**calculate fines**, **edit records**, and **store data permanently**
using file handling.

------------------------------------------------------------------------

## 🚀 **Features**

✔ Issue a book\
✔ Return a book with **automatic fine calculation**\
✔ View all issued books\
✔ Edit book/user details\
✔ Delete book records\
✔ Prevent issuing duplicate Book IDs\
✔ Persistent storage using binary file (`library.dat`)\
✔ Simple and menu-driven interface

------------------------------------------------------------------------

## 🛠️ **Technologies Used**

-   **C Language**
-   **File Handling (Binary Mode)**
-   **Structures**
-   **Array Storage**
-   **Basic Date Calculations**

------------------------------------------------------------------------

## 📂 **Project Structure**

``` plaintext
LibraFlow/
│── library.dat        # Auto-generated database file
│── main.c             # Full source code
│── README.md          # Project documentation
```

------------------------------------------------------------------------

## 📷 Screenshots

### Main Menu
![LibraFlow Main Menu](https://github.com/swastimayee354/LibraFlow/blob/08b284cd4ced9d285161a360368c8cdc080c3f13/LIBRAFLOW_CHOICE-01.png)

### Issue a Book
![Issue a Book](https://github.com/swastimayee354/LibraFlow/blob/08b284cd4ced9d285161a360368c8cdc080c3f13/LIBRAFLOW_CHOICE-02.png)

### Return a Book & Fine
![Return Book and Fine](https://github.com/swastimayee354/LibraFlow/blob/08b284cd4ced9d285161a360368c8cdc080c3f13/LIBRAFLOW_CHOICE-03.png)

### View All Issued Books
![View Issued Books](https://github.com/swastimayee354/LibraFlow/blob/08b284cd4ced9d285161a360368c8cdc080c3f13/LIBRAFLOW_CHOICE-04.png)

### Edit / Delete Records
![Edit or Delete Records](https://github.com/swastimayee354/LibraFlow/blob/08b284cd4ced9d285161a360368c8cdc080c3f13/LIBRAFLOW_CHOICE-05.png)

------------------------------------------------------------------------


## 📥 **How to Run the Project**

### **1. Compile**

``` bash
gcc main.c -o LibraFlow
```

### **2. Run**

``` bash
./LibraFlow
```

------------------------------------------------------------------------

## 📘 **How It Works**

### **➤ Issue Book**

-   Enter Book ID\
-   Book Name\
-   User Name\
-   Issue Date\
-   Automatically saved in `library.dat`

### **➤ Return Book & Fine Calculation**

-   If returned **within 14 days → No fine**\
-   After 14 days → Fine = (Days Late × ₹2)

### **➤ View Issued Books**

Displays:

    ID | Book Name | User | Issue Date

### **➤ Edit Book Record**

Update: - Book name\
- User name\
- Issue date

### **➤ Delete Book**

Removes the record permanently.

------------------------------------------------------------------------

## 📸 **Sample Terminal Output**

    =========== Library Management System ===========
    1. Issue a Book
    2. Return a Book & Calculate Fine
    3. View All Issued Books
    4. Edit Book Details
    5. Delete Book Record
    6. Exit
    Enter your choice:

------------------------------------------------------------------------

## 🔐 **Data Storage**

All records are stored in:

    library.dat

Using binary write (`wb`) and read (`rb`), ensuring fast and compact
data storage.

------------------------------------------------------------------------

## 📄 **Source Code**

Complete source code is available in the repository under `main.c`.

------------------------------------------------------------------------

## 👨‍💻 Author
**Swastimayee Parida**  
Developer & Creator of **LibraFlow**  
Passionate about C programming and simple system applications.


------------------------------------------------------------------------

## ⭐ **If you like this project, consider giving it a star!** ⭐
