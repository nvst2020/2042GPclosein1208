void R5()
{
    // 輸入 Reader ID，查找對應的讀者帳戶
    const string readerID = readLine("Please enter Reader ID: ");
    const int index = findReader(readerID);
    if (index == -1)
    {
        cout << "Reader ID does not exist.\n";
        return;
    }

    const Reader& reader = readers[index];
    const string statementDate = systemDate.substr(8, 2) + "-"
                               + systemDate.substr(5, 2) + "-"
                               + systemDate.substr(0, 4);
    const string divider(68, '-');
    const auto originalFlags = cout.flags();

    // 顯示 Reader Name、Reader ID、圖書證號碼及報表日期
    cout << "\nReader Name: " << reader.Name
         << "\nReader ID: " << reader.ID
         << "\nLibrary Card Number: " << reader.CardNumber
         << "\nStatement Date: " << statementDate << "\n\n"
         << divider << "\nTransactions:\n" << left
         << "\nStatement Date: " << statementDate << "\n\n";

    // 顯示 Transactions 交易表格，包括類型、積分變動及說明
    cout << divider << "\nTransactions:\n" << left
         << setw(18) << "Type" << setw(18) << "Reading Points"
         << "Description\n";

    for (const Transaction& transaction : transactions)
    {
        if (transaction.readerID == readerID)
        {
            cout << setw(18) << transaction.type
                 << setw(18) << transaction.points
                 << transaction.description << '\n';
        }
    }

    // 顯示 Borrowing History 借閱歷史，包括書名、借閱日期及到期日
    cout << '\n' << divider << "\nBorrowing History:\n"
         << setw(10) << "eBook ID" << setw(27) << "Title"
         << setw(18) << "Borrowing Date" << "Due Date\n";

    for (const Borrowing& loan : borrowings)
    {
        if (loan.ReaderID == readerID)
        {
            const EBook* book = findEBook(loan.eBookID);
            cout << setw(10) << loan.eBookID
                 << setw(27) << (book ? book->title : "Unknown")
                 << setw(18) << loan.BorrowingDate << loan.DueDate << '\n';
        }
    }

    cout.flags(originalFlags);
    // 顯示 Reader Account Summary 帳戶摘要，包括積分及兩類結轉餘額
    cout << divider << "\nReader Account Summary:\n"
         << "Total Reading Points Balance: " << reader.Points << '\n'
         << "Fiction Rollover Balance: " << reader.Fiction << '\n'
         << "Non-Fiction Rollover Balance: " << reader.NonFiction << '\n';
}


void R6(int &option)
{
    string ans;
    do
    {
        cout << "Would you like to exit now? (Yes/No): ";
        cin >> ans;

        if (ans == "Y" || ans == "y")
        {
            cout << "Group Member: \n";
            cout << "WONG Yam Chung 25015029A   A02A\n";
            cout << "KWAN Sze Man   25036800A   A02A\n";
            cout << "CHEN Jinxiang  25040155A   A02B\n";
            cout << "FU Kei Leung   25099927A   A02B\n";
            cout << "CHOW Nok Hei   25201465A   A02A\n";
            cout << "NG Lap Yin     25204013A   A02C\n";
            option =6;
            break;
        }
        else if (ans == "N" || ans == "n")
        {
            option = 1;
            break;
        }
        else
        {
            cout << "Please type your option again!" << endl;
        }

    } while (ans != "Y" || ans != "y" || ans != "N" || ans != "n");
}
