// Generated with https://github.com/kiwiyou/basm-rs
// Learn rust (https://doc.rust-lang.org/book/) and get high performance out of the box!

#![crate_type = "cdylib"] // On Windows, omit this or pass '--crate-type=bin' to rustc to avoid DLL creation.
#![cfg_attr(not(windows), no_std)]#![allow(unused)]#[no_link]extern crate std as s;

// SOLUTION BEGIN
#[cfg(any())] mod solution {
use basm::platform::io::{Reader, ReaderTrait, Writer};
pub fn main() {
    let mut reader: Reader = Default::default();
    let mut writer: Writer = Default::default();

    let a: i128 = reader.i128();
    let b: i128 = reader.i128();

    if a > b {
        writer.str(">");
    } else if a < b {
        writer.str("<")
    } else {
        writer.str("==")
    }
}
}
// SOLUTION END

// LOADER BEGIN
#[cfg(not(all(target_arch = "x86_64", any(windows, target_os = "linux"))))]
compile_error!("Unsupported target architecture or operating system.");
macro_rules! p { () => { "stc" } }
#[cfg(windows)]
macro_rules! p { () => { "call LoadLibraryA;lea rdx,[rip+GetProcAddress];lea rdi,[rip+VirtualAlloc];clc" } }

static mut PAYLOAD: [u8; 1585] = *br"%Q$$,$PH$$r-YNddS^agLJ'S6Bi5hPFJ3%,Y]M--gfyeTnbPl&$]b5LwNaHEq`;`G>9_V9[AwgQg^pDXFfI0yX,jdhzCOl&]ggLf'9=b:>ZerR_}Z30-*/eUxy0{x'U@[.X8c+zmX2kW+8t=Z>.c09pt;>fJk='bz%Ld4EU|(\msb}B0I9Uk\P\XX-P`l]Y7Qs'=8y,%g]lH-H><;wbi.JWpqJg`Qy8U=+*,*2*QELyAqk?]v;U%NzkgDRo?FrKyJv_awLEB9b\XA5_,2}({bRH^Em4suH)UG1ynH2'1lQC|3m@8gp;4()<$RY+U8hw-j'H$:J?Ml3KQf}kHf\)E-0<GbSyD?2'Vb>FCvEgcDTQy|{'.qQvZmPRi'HFAz1?@A`b,ni.npr8X(WnhZA;mew{xHRQw]V:?;q)X^}+UfkmjC@b])P.BIBtBM5y/[{;/SR_tA|+'*m4QMAF[Q\N%^&S%ba`4(F{o:,aeZ-s16y^GyS~2t3LSqmVJXJOlfD%NkAf(K/Nrx8&u%l$OXOI<7-J'Dt,n9sM1pI\l_\_;uJzchXr[Qr<fc?(1,rt5=pCmb`$r'+tqcz\pCc$SRW'odMOYxLLq^8.or)&gL`NSB)XN5TR[j}R$z.nuhRxQ;gJ..zglH@2N0CUI||XXj&]g}^G\mzIQU%T'e8K:U@t`DlL[`Dn2z0?kg5'u@%.k4HKekmmg>q;[TOm*lCSgXdB.5@A4Q%1dq$>]+mY_~Oa|;l^O0c['aSI4a7H_2GA/^u}NELGcO\hmtTPWy}(O;)8N1eX)u3,:44>?GGUch{b<Wq\0KEgm+Z156pTAd62i9?A)Y3A).U7}0e&ylysYyrgkuJlw$TT@jrqs:dUL|UWS~*7?Cs1&wl04^1:QQLJCpGq>RGWzNyG+ajpe<no:LvL^/S2uK.i=U))E^g'jbZf|ee?L/cP2^Sv6xEMn27LT~Jh>d:Q7oj&k$AGU''`O8<Nr;Yj;CWbtzfkJxNum_.Sfx0'&aI8g+D[4q1$>osSi|ndGE>W)[0a.q[P<2|n<@X?]n'm;iQwicRtSbxDCR>I{8l/9BoT;Ok9S|t%mV=_GNiY<4syq\/<bIun=(0[?'oFBp0Ad^p${OsEQLLyXq(%S:`K&b>N;lVdq&/>;n&R*x(%T{ni</pM?EOf}qp+S+0)_jFFtaj_vq4SJsnsrdye6AH6^~h`2]d,w'3F0Ng,rXu>_>dE|[b2a(9X6bV$u|nYdeyUrQgw4m9/|~R>S^ar&,eE*=6`C_nzJLq|viAs9:SC&}Fe:8(ys}v<\T.fvG_%t>DWF2fyvlXOj.]dw8QF7A{J@\EdBK%,2=LjG@%&d7zROusgln.:dP0tM0/;.$4GzK<`,Ub3&`1=J_FLp;r&1z,CJ(U`pkl(ve)KP=3yblw?]{Sc@KT%p7k2G=wzDbVZFyz.T8iKAy@_K&|k=Sja=yASx3rl{uksO5t2Qx%tv)tvq{w;[%YnXe}5c5RjU+BS=.|tgwz}s(n(.,6l><t%R*oQFcotDTip-\^$7J%a)rO;%8[drP}5RQ=;g4*<a7%\IGeRwV91z=:$'aka-Sw5$clQ:zG`f!";
#[no_mangle]
unsafe fn _start() {
    s::arch::asm!(p!(),
        ".quad 19510173000030c8h,4ce8d9f7c9h,459927e36758096ah,870d74ff8548c931h,\
        4100003000b841cah,0b2ce8956e7ff40b1h,41ff6a5a41226a07h,0c11fb0c35e050f58h,\
        99f572242cac0de0h,15bc06b242cac92h,10c4f608e8c1aad0h,5052535be3ebf775h,\
        20ec834851c1ff51h,0c93197485750d3ffh,90c9d0ff585fd3ffh",
        in("rcx") "KERNEL32\0".as_ptr(), in("r14") PAYLOAD.as_mut_ptr(), in("rsi") r"-n[b4n2|3|z+6|EI_'v:ZWHZ}\DWh'i'j'd<^V^VrTubU$7?Y`xGcbG67?Y`zGA(ocPYN&)$,$;/*]fU\)w$1]]T8?j]Td~_hpAtUmVHd/T8d/*>Va^h7{]uV7R+'_N-pX@=MRg+uQ^8F|CZWSm$0@^VyMR:$$sd;;>%g|50;BcHEN[?<ko?F-$\M=MhA)L;tO@'Zg$$]<GjL>o_Hxrois1&*9%QaL[']h%=9hS%%|hXW3~.ns2>N1;;1=oXxbVNMeb=^iZ4n]V8w{cl-A06{{pki.9^XHQq%Q,$])cn</advVEQ--TY'm_sbV5Qo(Z3OgQe5)DW''DTL&UVFdvyE$3);)2dRg0pT]xlW&q&$$i0:Kv*s7Fj,TE1(Q:/$YBNG{jQ?@;29YoT8Yb7hE$Y0p$[8{FSN|%JY}J=a<$$^V4m.w}}*dyB;t,`v^LxRguWe|lsoLEhfVL(n]^l$QX}b<At,V'$,Uj(irn[8@zy8U|4*+x.&/UA^)xbi'A7RgrTvPFdK6vb4/GR]1LZ't_-=h*:GDya=$m,zy2n0]OIemm&5V]?R}i>H8uWL-4/bV)>_}\?T}T}-dAS]+2m{h\7N|U{e<of$~]V|sME<kplL;YkG=L;WxoD{h~1f-6ii'W}s<rTIgFdR=g.caW)<7\)69\s9q]W-J==DY6)4Qjtw&0XZ=\)hEVlDuAH$~XuGID0`@DkPh:-9hcd[?x{C*q'`WPsHy(%1&!".as_ptr()
    )
}
fn main() { unsafe { _start() } }
// LOADER END
