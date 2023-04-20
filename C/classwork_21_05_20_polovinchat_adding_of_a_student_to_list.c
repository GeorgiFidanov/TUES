
void addtoboth(char *filename, struct list *students, struct student newstudent){

    add(newstudent, students);
///izvikvane veche gotova fukciq ot predi tova, za da zapishem nov uchenik
    FILE *f = fopen(filename, "rb+");
///otvarqme file
    int size = students -> size;

    fwrite(&size, sizeof(int), 1, f);
///zapisvame broqt na uchenicite
    fseek(f, 0, SEEK_END);

    fwrite(&newstudent, sizeof(struct student), 1, f);
///dobavqme novqt uchenik v faila i strukturata
    fclose(f);
///zatvarqme file-a
}

void edit(char *filename, struct list *students, int grade, char classname, int number, int index){

    struct student st = students -> arr[index];

    st.grade = grade;
    st.className = classname;
    st.number = number;
///zadavame parametrite na novata ni struktura student
    students -> arr[index] =st;

    FILE *f = fopen(filename, "rb+");
///otvarqme file
    fseek(f, sizeof(int) + (index * sizeof(struct student)), SEEK_SET);

    fwrite(&st, sizeof(struct student), 1, f);
///dobavqme novqte(promeneni) stoinosti  na uchenik v faila i strukturata
    fclose(f);
///zatvarqme file-a
}
