// https://app.codesignal.com/interview-practice/task/FwAR7koSB3uYYsqDp

std::string findProfession(int level, int pos) {
    // every level starts from "Engineer" on the left
    if (level == 1)
        return "Engineer";
    
    // bottom-up recursion
    string parent = findProfession(level-1, (pos+1)/2); // already ceiling in C++
    
    if (parent == "Engineer") {
        if ((pos-1) % 2 == 0)
            return "Engineer";
        else
            return "Doctor";
    }
    else {
        if ((pos-1) % 2 == 0)
            return "Doctor";
        else
            return "Engineer";
    }
}

