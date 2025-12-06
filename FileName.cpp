#include <iostream>
#include <deque>
#include <cstdint>
#include <functional>

//world rolling as by INS.
//Work pattarn is x86. this time.
//work pattarn mini is x68.
//so we need data.

// are you need this like a PU. but NOT FOR SELL!!!!!!!!!!!!!!!!

struct Executer {
	std::size_t Pointer = 0;
	//typedef std::int8_t INSLong;
	enum class INS { None, jmp, No, x, I21, x0N, lb, push, pop, reg, mem, zero, one, exe, ret, bel, uld, scl, norn, None, min, max,fwd,ack ,up,dwn,yld,nue,stop};
	enum class x86 { None, jmp, No, x, I21, x8N, add, sub, mul, div, mod, And, Or, Nand, Nor, Xor, Not, Eq, LOAD, STORE, DATA,up,dwn, };
	enum class x68 { None, jmp, No, x, I21, x6N,up,dwn, Ab, Ba, Ac, Bc, Ca, Cb, A, B, C, Xc,Cx,X,NI,NF,Ni,NM,NCi,NCf,NCii,NCif,NCfi,NMi,NMf, };
	std::deque<INS> seque;
	typedef std::int8_t byte;
	std::deque<byte> Data;
	std::function<std::deque<Executer::INS>(Executer& ,Executer::INS)> Exeri = [](auto& e,INS I)->std::deque<Exeuter::INS> {return { Exeuter::INS::None }; };
	std::intmax_t X = 0;//register.

	struct SubCuter {
		std::intmax_t No = -1;
		Executer::x86 Nim;
		Executer::x68 DataX;
		std::intmax_t A = 0;//register.
		std::intmax_t B = 0;//register.
		std::intmax_t C = 0;//register.
	};

	std::deque<SubCuter>SC;
};


void Forward(Executer& E) {
	E.Pointer++;
}
void Backward(Executer& E) {
	E.Pointer--;
}
void Exe(Executer& E) {
	auto N = E.Pointer;
	auto dq1 = std::deque<Executer::INS>();
	auto dq2 = std::deque<Executer::INS>();
	dq1 = E.Exeri(N);
	do {
		dq2.clear();
		for (auto& o; dq1) {
			auto A = E.Exeri(E,o);
			dq2.insert(dq2.end(), A.begin(), A.end());
		}
		for (auto& o; dq2) {
			auto A = E.Exeri(E,o);
			dq1.insert(dq1.end(), A.begin(), A.end());
		}
	} while (dq1.size()!=0);
}
void ExLambada(Executer& E, const auto& L) {
	E.Exeri = L;
}
void ExSequence(Executer& E, std::deque<Executer::INS>& In) {
	E.seque = In;
}

int main() {
	std::deque<Executer::INS> Seq={}
}