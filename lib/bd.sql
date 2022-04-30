#drop database agencia;
create database agencia;
use agencia;


create table setor(
codSetor integer not null auto_increment,
nomeSetor varchar(100),
primary key(codSetor)
);

insert into setor(nomeSetor) values("RH");
insert into setor(nomeSetor) values("Vendas");
insert into setor(nomeSetor) values("Trocas");
insert into setor(nomeSetor) values("Manutencão");

select * from setor;

create table carro(
placa varchar(20) not null,
nomeCarro varchar(100) not null,
modelo varchar(100) not null,
ano integer not null, 
valor double not null,
qntEstoque integer not null default 0,
codSetor integer not null,
situacao varchar(50) not null default "disponível", 
primary key(placa),
foreign key(codSetor) references setor(codSetor)
);

insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("abc1g34", "hb20", "sedan 1.5", 2020, 43220.54, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("tre5e65", "argo", "flet 1.3", 2019, 58201.63, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("gna4k94", "argo", "flet 1.3", 2019, 58201.63, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("qwe4n32", "argo", "flet 1.3", 2019, 58201.63, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("hrt6r75", "brasilia", "sedan 1.5", 1990, 24587.98, 3);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("dbx4a89", "parati", "sedan 1.2", 1995, 36142.02, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("lkj0f61", "marajó", "sedan 1.0", 1997, 74201.95, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("nht6i08", "ipanema", "sedan 1.5", 1993, 56058.97, 3);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("qgc4h86", "gol", "flet 1.3", 2015, 39789.41, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("qjv3t00", "uno", "flet 1.2", 2016, 98630.25, 3);
#insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("hyp2h83", "palio", "flet 1.0", 2010, 48562.30, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("xzs2l97", "crossfox", "sedan 1.5", 2011, 67841.29, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("ncx5r58", "siena", "sedan 1.3", 2013, 50004.80, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("kqo6y98", "celta", "flet 1.2", 2009, 26086.73, 3);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("lpd4f67", "onix", "flet 1.6", 2020, 82369.54, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("lop0b73", "x4", "sedan 2.0", 2018, 100000, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("gsd5e51", "panamera", "sedan 3.0", 2017, 200000, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("fqs7r01", "up", "sedan 1.0", 2019, 20000, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("tqy8y52", "virtus", "sedan 3.0", 2016, 50000, 2);
insert into carro(placa, nomeCarro, modelo, ano, valor, codSetor) values("mzx5g76", "compass", "sedan 3.0", 2018, 60000, 2);

select * from carro;

create table funcionario(
cpfFuncionario varchar(20) not null,
nomeFuncionario varchar(100) not null,
enderecoFuncionario varchar(100) not null,
salario double not null, 
codSetor integer not null,
primary key(cpfFuncionario),
foreign key(codSetor) references setor(codSetor) on delete cascade
);

insert into funcionario values("01", "pedro almeida", "Rua Joao IX 416", 2005.23, 2);
insert into funcionario values("02", "joao siqueira", "Rua Maria 568", 3025.85, 2);
insert into funcionario values("03", "guilherme costa", "Rua Pio XII 789", 2987.25, 1);
insert into funcionario values("04", "gabriel rosa", "Avenida JK 230", 4017.36, 3);
insert into funcionario values("05", "nicholas caponne", "Avenida Paulista 369", 1100.69, 4);
insert into funcionario values("06", "leonardo favorreto", "Avenida 9 de Julho 412", 1900.48, 4);
insert into funcionario values("07", "mateus cicarelli", "Rua Rio Branco 478", 3698.47, 3);
insert into funcionario values("08", "carlos nunes", "Rua Beira-Rio 012", 5587.87, 2);
insert into funcionario values("09", "eduardo angeli", "Rua Washington 589", 2148.64, 1);

select * from funcionario;

create table cliente(	
cpfCliente varchar(20) not null,
nomeCliente varchar(100) not null,
telefone integer,
enderecoCliente varchar(100) not null,
placa varchar(10) null, 
cpfFuncionario varchar(20) not null,
primary key(cpfCliente),
foreign key(cpfFuncionario) references funcionario(cpfFuncionario) on delete cascade
);

insert into cliente values("10", "lara da costa", 45678912, "Rua da Oficina 504", "dbx4a89", "01");
insert into cliente values("11", "julia ferreira", 12540368, "Rua Ipres 256", "abc1g34", "01");
insert into cliente values("12", "paula federer", 14785962, "Rua Santo Angilberto 102", "tre5e65", "01");
insert into cliente values("13", "maria fernanda souza", 25896301, "Rua Ponte 234", "lkj0f61", "02");
insert into cliente values("14", "laura chueire", 12547890, "Rua Bom Jardin 478", "qgc4h86", "04");
insert into cliente values("15", "natalia falavigna", 98563201, "Avenida Cesar Morini 2047", "hyp2h83", "05");
insert into cliente values("16", "maria eduarda trevizan", 78126935, "Rua Alberto Leite 032", "xzs2l97", "06");
insert into cliente values("17", "fernanda castro", 25980364, "Rua Pavao 604", "ncx5r58", "08");
insert into cliente values("18", "milena maiyuri", 23650148, "Rua Zacarias Silva 600", "lpd4f67", "08");
insert into cliente values("19", "guilia cardi", 58006987, "Rua Estremadura 306", "hrt6r75", "08");
insert into cliente values("20", "marcela garcia", 85490360, "Rua do Sergipano 703", "nht6i08", "08");
insert into cliente values("21", "ana valdes", 78403601, "Rua Pafos 499", "kqo6y98", "04");
insert into cliente values("22", "julia maria", 25000236, "Rua Capanga", "qwe4n32", "01");
insert into cliente values("23", "marta", 50047039, "Rua 14 de Marco", "gsd5e51", "02");
insert into cliente values("24", "rebeca", 58001403, "Rua 12 de Abril", "fqs7r01", "02");
insert into cliente values("25", "deise", 69030170, "Rua jorge abreu", "tqy8y52", "08");

select * from cliente;

create table comando(
idComando integer auto_increment,
cpfFuncionario varchar(20) not null,
cpfCliente varchar(20) not null,
placa varchar(20) not null,
codSetor integer not null,
dataOperacao date not null,
placaTroca varchar(20) null default null,
valorOperacao double null,
primary key(idComando),
foreign key(cpfFuncionario) references funcionario(cpfFuncionario) on delete cascade,
foreign key(cpfCliente) references cliente(cpfCliente) on delete cascade,
foreign key(codSetor) references setor(codSetor)
);

insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("04", "14", "qgc4h86", 2, 20161214, 39789.41);
update carro set situacao = "vendido" where placa = "qgc4h86";

insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("01", "10", "dbx4a89", 2, 20201212, 36142.02);
update carro set situacao = "vendido" where placa = "dbx4a89";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("01", "11", "lkj0f61", 2, 20191019, 74201.95);
update carro set situacao = "vendido" where placa = "lkj0f61";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("01", "12", "tre5e65", 2, 20180808, 58201.63);
update carro set situacao = "vendido" where placa = "tre5e65";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("01", "22", "qwe4n32", 2, 20200606, 58201.63);
update carro set situacao = "vendido" where placa = "qwe4n32";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("01", "22", "qwe4n32", 4, 20160606, 200);
update carro set situacao = "revisao" where placa = "qwe4n32";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("02", "23", "gsd5e51", 2, 20150505, 200000);
update carro set situacao = "vendido" where placa = "gsd5e51";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("02", "23", "fqs7r01", 2, 20200109, 20000);
update carro set situacao = "vendido" where placa = "fqs7r01";
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, valorOperacao) values ("08", "23", "tqy8y52", 2, 20170707, 50000);
update carro set situacao = "vendido" where placa = "tqy8y52";
update carro set situacao = "vendido" where placa = "gna4k94";

select * from comando;





/*
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, placaTroca, valorOperacao) values ("05", "15", "nht6i08", 3, 20101118, "hyp2h83", 56058.97-48562.30);
insert into comando(cpfFuncionario, cpfCliente, placa, codSetor, dataOperacao, placaTroca, valorOperacao) values ("05", "15", "lop0b73", 3, 20101010, "nht6i08", 100000-56058.97);
*/

/*
#-------------------------------------------------- consultas -------------------------------------------------------
#1 on carro.placa = comando.placa
select modelo from
(select max(qnt) maximo from (select count(modelo) qnt from carro natural join comando where comando.codSetor = 2 and dataOperacao < 20210101 and dataOperacao > 20200101 group by modelo) a) b
join
(select modelo, count(modelo) qnt2 from carro natural join comando where codSetor = 2 group by modelo) c
on maximo = qnt2;

#2
select nomeCarro from 
(select max(qnt) maximo
from (select count(nomeCarro) qnt from carro where situacao = "vendido" group by nomeCarro) a) b
join
(select nomeCarro, count(nomeCarro) qnt2 from carro where situacao = "vendido" group by nomeCarro) c
on maximo = qnt2;
select * from carro;
select count(nomeCarro) qnt from carro where situacao = "vendido" group by nomeCarro;

#3 ---- falta a troca ---------
select sum(valorOperacao) from comando where codSetor = 2 and dataOperacao > 20000101 and dataOperacao < 20170101;
select sum(valorOperacao) from comando where codSetor = 3 and dataOperacao > 20000101 and dataOperacao < 20170101;
select *from comando;

#4
select cpfCliente from 
(select cpfCliente, count(cpfCliente) qnt from comando where codSetor = 3 and dataOperacao < 20110101 and dataOperacao > 20100101 group by cpfCliente) a
where qnt > 1;

#5
select sum(salario) from funcionario;

#6
select cod1, qntFuncionarios, sal from
(select codSetor cod1, count(cpfFuncionario) qntFuncionarios from funcionario group by codSetor) a
join
(select codSetor cod2, sum(salario) sal from funcionario group by codSetor) b
on cod1 = cod2;

#7
select nomeCliente, cpfCliente from cliente natural join comando where codSetor = 4 and dataOperacao < 20200101;

#8
select cpfCliente, sum(valorOperacao) valorGasto from comando where codSetor = 2 group by cpfCliente;

#9
select modelo, count(modelo), sum(valor) from carro where situacao = "disponivel" group by modelo;

#10
select nomeCliente, comando.cpfCliente from cliente natural join comando where dataOperacao < 20170101 and codSetor = 3 group by cpfCliente;

# tenho q rever a 11 e 12 q ACHO so dao o max
#11// tenho q rever- tem q mostrar apenas 2 funcionarios
-- select nomeFuncionario, cpfFuncionario, max(qnt), min(qnt) from 
-- (select nomeFuncionario, cpfFuncionario, sum(valor) qnt from funcionario natural join comando join carro on carro.placa = comando.placa group by cpfFuncionario) a
-- group by cpfFuncionario;

select nomeFuncionario, cpfFuncionario, count(cpfFuncionario) vendeu from funcionario natural join comando where codSetor = 2 group by cpfFuncionario;

select * from funcionario;

#12
select nomeFuncionario, cpfFuncionario, maximo from 
(select max(qnt) maximo from 
(select nomeFuncionario, cpfFuncionario, sum(valor) qnt from funcionario natural join comando join carro on carro.placa = comando.placa group by cpfFuncionario) a) b
join
(select nomeFuncionario, cpfFuncionario, max(qnt2) maximo2 from
(select nomeFuncionario, cpfFuncionario, sum(valor) qnt2 from funcionario natural join comando join carro on carro.placa = comando.placa group by cpfFuncionario) c) d
where maximo = maximo2;
update funcionario set salario = salario*1.06 where cpfFuncionario = 01; #o resultado de cima
select * from funcionario;

#13
select nomeFuncionario, cpfFuncionario, min(vendeu) minimo from
(select nomeFuncionario, cpfFuncionario, sum(valor) vendeu from funcionario natural join comando natural join carro where codSetor = 2 group by cpfFuncionario) a;

select nomeFuncionario, cpfFuncionario, sum(valor) vendeu from funcionario natural join comando natural join carro where codSetor = 2 group by cpfFuncionario order by vendeu;
select nomeFuncionario, cpfFuncionario, sum(valor) vendeu from funcionario natural join comando natural join carro where codSetor = 2 group by cpfFuncionario order by vendeu desc;

#14
select cpfCliente, sum(valorOperacao) valorGasto from comando group by cpfCliente order by valorGasto;

#15
select cpfCliente from 
(select cpfCliente, sum(valorOperacao) valorGasto from comando where dataOperacao < 20110101 group by cpfCliente) a where valorGasto is null;

select * from comando;

update carro set situacao = "trocado" where placa = "nht6i08";
update cliente set placa = "nht6i08" where cpfCliente= "15";
------------------
update carro set situacao = "trocado" where placa = "lop0b73";
update cliente set placa = "lop0b73" where cpfCliente= "15";
select nomeFuncionario, cpfFuncionario, sum(valor) vendeu from funcionario natural join comando natural join carro where codSetor = 2 group by cpfFuncionario order by vendeu;
*/


update carro set situacao = "trocado" where placa = "nht6i08";
update cliente set placa = "nht6i08" where cpfCliente= "15";
------------------
update carro set situacao = "trocado" where placa = "lop0b73";
update cliente set placa = "lop0b73" where cpfCliente= "15";



