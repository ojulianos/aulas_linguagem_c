struct contato {
    char nome[20];
    char email[50];
};

typedef struct contato CONTATO;

int main() {
    /*
    cadastra um novo registro na struct
    */
    CONTATO juliano;
    strcpy(juliano.nome, "juliano silva");
    strcpy(juliano.email, "juliano.si6@gmail.com");

    /*
    faz a cópia completa do struct juliano em silva
    */
    CONTATO silva;
    memcpy(&silva, &juliano, sizeof(CONTATO));

    /*
    memset inicia uma struct com valor nulo dessa forma evita o lixo do compilador
    serve como gabage collector
    */
    CONTATO maria;
    memset(&maria, 0, sizeof(CONTATO));
}
