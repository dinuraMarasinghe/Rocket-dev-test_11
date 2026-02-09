MENU:
PRINT "===== LIBRARY MANAGEMENT SYSTEM ====="
PRINT "1. Add Member"
PRINT "2. Add Book"
PRINT "3. Borrow Book"
PRINT "4. List Member Borrowings"
PRINT "5. Exit"
INPUT "Choose option: ": OPTION

SELECT OPTION
CASE 1
    GOSUB ADD_MEMBER
CASE 2
    GOSUB ADD_BOOK
CASE 3
    GOSUB BORROW_BOOK
CASE 4
    GOSUB LIST_BORROWED
CASE 5
    STOP
END

GOTO MENU


ADD_MEMBER:
PRINT "Enter Member ID: "
INPUT MEMID

IF READ(MEMID, "MEMBERS") THEN
    PRINT "Member already exists!"
    RETURN
END

PRINT "Enter Member Name: "
INPUT MEMNAME
PRINT "Enter Phone Number: "
INPUT PHONE

MEMBERS<1> = MEMNAME
MEMBERS<2> = PHONE
WRITE MEMBERS, MEMID

PRINT "Member added successfully!"
RETURN


ADD_BOOK:
PRINT "Enter Book ID: "
INPUT BOOKID

IF READ(BOOKID, "BOOKS") THEN
    PRINT "Book already exists!"
    RETURN
END

PRINT "Enter Book Title: "
INPUT TITLE
PRINT "Enter Available Copies: "
INPUT COPIES

BOOKS<1> = TITLE
BOOKS<2> = COPIES
WRITE BOOKS, BOOKID

PRINT "Book added successfully!"
RETURN


BORROW_BOOK:
PRINT "Enter Member ID: "
INPUT MEMID

IF NOT READ(MEMID, "MEMBERS") THEN
    PRINT "Member not found!"
    RETURN
END

PRINT "Enter Book ID: "
INPUT BOOKID

IF NOT READ(BOOKID, "BOOKS") THEN
    PRINT "Book not found!"
    RETURN
END

COPIES = BOOKS<2>

IF COPIES <= 0 THEN
    PRINT "No copies available!"
    RETURN
END

BOOKS<2> = COPIES - 1
WRITE BOOKS, BOOKID

BORROW<1> = MEMID
BORROW<2> = BOOKID
WRITE BORROW, MEMID:BOOKID

PRINT "Book borrowed successfully!"
RETURN


LIST_BORROWED:
PRINT "Enter Member ID: "
INPUT MEMID

IF NOT READ(MEMID, "MEMBERS") THEN
    PRINT "Member not found!"
    RETURN
END

KEY = ""

PRINT "Borrowed Books:"
PRINT "----------------"

LOOP:
KEY = NEXT KEY FROM "BORROW"
IF KEY = "" THEN EXIT

READ BORROW, KEY
IF BORROW<1> = MEMID THEN
    READ BOOKS, BORROW<2>
    PRINT "Book ID: ": BORROW<2>
    PRINT "Title  : ": BOOKS<1>
    PRINT "----------------"
END

GOTO LOOP
RETURN

