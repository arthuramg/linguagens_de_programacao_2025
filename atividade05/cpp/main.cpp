#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double horaAdmin = 22.00;
const double horaProducao = 12.00;
const double taxaInss = 0.07;
const double taxaIr = 0.12;
const double planoDeSaude = 20.00;
const int NumMaxFuncionario = 5;

struct Funcionario {  //classe do funcionário
    string nome;
    int departamento;
    double horasTrabalhadas;
    double salarioHoras;
    double horasExtra;
    double insalubridade;
    double bonificacao;
    double salarioBruto;
    double inss;
    double impostoDeRenda;
    double salarioLiquido;
};

double calcularSalarioBase(int departamento, double horasTrabalhadas) {
    double valorHora = (departamento == 1) ? horaAdmin : horaProducao;
    return horasTrabalhadas * valorHora;
}

double calcularHoraExtra(int departamento, double horasTrabalhadas) {
    if (horasTrabalhadas <= 40) return 0.0; //fez ou não hora extra
    double valorHora = (departamento == 1) ? horaAdmin : horaProducao; //if else pra prod ou admin e passa o valor abaixo
    return  valorHora * 2 * (horasTrabalhadas - 40);
}

double calcularInsalubridade(int departamento, double salarioHoras) {
    return (departamento == 2 ) ? salarioHoras * 0.15 : 0.0;
}

double calcularBonificacao(int departamento, double horasTrabalhadas, double salarioHoras) {
    if (departamento != 1) return 0.0;
    if (horasTrabalhadas > 40) return salarioHoras * 0.10;
    if (horasTrabalhadas > 30) return salarioHoras * 0.05;
    if (horasTrabalhadas > 20) return salarioHoras * 0.03;
    return 0.0;
}

double calcularSalarioBruto(double salarioHoras, double horasExtra, double insalubridade, double bonificacao) {
    return salarioHoras + horasExtra + insalubridade + bonificacao;
}

double calcularInss(double salarioBruto) {
    return salarioBruto * taxaInss;
}

double calcularImpostoDeRenda(double salarioBruto) {
    return salarioBruto * taxaIr;
}

double calcularSalarioLiquido(double salarioBruto, double inss, double impostoDeRenda){
    return salarioBruto - impostoDeRenda - inss - planoDeSaude;
}

void exibirFolhaDePagamento(const Funcionario funcionarios[], int tamanhoMax) {
    cout << "Ordem  Nome           Salario Base   Hora Extra  Insalubridade   Bonificacao  INSS      IR        Plano Saude  Salario Liquido\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < tamanhoMax; ++i) {
        const Funcionario& func = funcionarios[i];
        cout << setw(5) << i + 1 << "  " //width
             << setw(15) << left << func.nome << " "
             << setw(15) << fixed << setprecision(2) << func.salarioHoras << " "
             << setw(10) << fixed << setprecision(2) << func.horasExtra << " "
             << setw(15) << fixed << setprecision(2) << func.insalubridade << " "
             << setw(12) << fixed << setprecision(2) << func.bonificacao << " "
             << setw(10) << fixed << setprecision(2) << func.inss << " "
             << setw(10) << fixed << setprecision(2) << func.impostoDeRenda << " "
             << setw(15) << fixed << setprecision(2) << planoDeSaude << " "
             << setw(15) << fixed << setprecision(2) << func.salarioLiquido << "\n";
    }
}

int main(){

    Funcionario funcionarios[NumMaxFuncionario];

    for (int i = 0; i < NumMaxFuncionario; ++i) {
        cout << "Funcionario " << i + 1 << ":\n";
        cout << "Nome: ";
        cin >> funcionarios[i].nome;
        cout << "Departamento (Digite 1 para Administrativo ou 2 para Producao): ";
        cin >> funcionarios[i].departamento;
        cout << "Horas trabalhadas: ";
        cin >> funcionarios[i].horasTrabalhadas;

        funcionarios[i].salarioHoras = calcularSalarioBase(funcionarios[i].departamento, funcionarios[i].horasTrabalhadas);
        funcionarios[i].horasExtra = calcularHoraExtra(funcionarios[i].departamento, funcionarios[i].horasTrabalhadas);
        funcionarios[i].insalubridade = calcularInsalubridade(funcionarios[i].departamento, funcionarios[i].salarioHoras);
        funcionarios[i].bonificacao = calcularBonificacao(funcionarios[i].departamento, funcionarios[i].horasTrabalhadas, funcionarios[i].salarioHoras);
        funcionarios[i].salarioBruto = calcularSalarioBruto(funcionarios[i].salarioHoras, funcionarios[i].horasExtra, funcionarios[i].insalubridade, funcionarios[i].bonificacao);
        funcionarios[i].inss = calcularInss(funcionarios[i].salarioBruto);
        funcionarios[i].impostoDeRenda = calcularImpostoDeRenda(funcionarios[i].salarioBruto);
        funcionarios[i].salarioLiquido = calcularSalarioLiquido(funcionarios[i].salarioBruto, funcionarios[i].inss, funcionarios[i].impostoDeRenda);
    }

    exibirFolhaDePagamento(funcionarios, NumMaxFuncionario);

    return 0;
}
