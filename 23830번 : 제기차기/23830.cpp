#include <unistd.h>
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
#define BASMCALL __attribute__((ms_abi))
void b91tobin(void *dest, char const *src) {
    u8 *p = (u8 *)dest;
    u32 eax = 0x1f;
    while (1) {
        while (*src == '\0') src++;
        u32 x = (u32) *src++;
        if (x < 0x24) return;
        while (*src == '\0') src++;
        u32 y = (u32) *src++;
        eax <<= 13;
        eax += (y - 0x24) * 91 + (x - 0x24);
        do {
            *p++ = (u32) eax;
            eax >>= 8;
        } while (eax & (1 << 12));
    }
}
#pragma pack(push, 1)
typedef struct {
    u64 env_id;
    u64 env_flags;
    u64 win[2];
    void *fn_table[6];
} PLATFORM_DATA;
#pragma pack(pop)
typedef int (BASMCALL *stub_ptr)(void *, void *);
char payload[][4096] = {
"%Q$$v&2R$$r-YNdd%Hag-17=DjRY(ng|G-yj>z{0vK9(}g['tTwf4@%~KIwGx3E*g1:m&lC9Nzk8/rlY*uOmiQsbccJ'B7~WXP*Oe|{{gRf822b>)$qoGaUs&*cNuP\\9UjINv5\\D\\R:*Ve-_}797HG]@pqvZ'uqLXpq;5>hfpU7lkReeMbdfBgZ2j^MsQZiPbKoFEvsXV`3'HB00|8(ra-CZie}2[J)nW.m-b:t+1/<|usohp,k_`2W9mP{Mps.\?sfkVhq,CadL}8QL*VD;kqC_S'+x-X=j_Na$a\?s2+fSB3xJHl(r.XX>78\?Yjrvtm3S'+|Kr;{aZu^rqB4/+%b3{iCf68}iD(7II]2X`V5uGu50*d/zN|.r2IH@nQ'0$0BgkmGD0b9_0die-V}/LGK6NreYMuwT+1U*\?b%u.:+xlmDk)Y5rCk-EJIHB9`D_SSq,ibILZx}.ie\?jyFI8'Lh0ImmcTO+8^ZBt03:U2_q3}tw@1.>{(Lv:R%\?7L<qNd996$7MIlnf53NsiZ;JeDVwCScXX8B8\\V|Ml0a}Chu\?KipMYp><vXWiHZXVc;ZiPLIUP%9cCaSW[_r9:^wW_OBfv8OpVG&|+c>0BH.Q'|XhZ8\?ng=MFe20\\4'%aQVS\\wi&pN|hWzg=TYvWc/[Ne.VKojV-=+l$~T17pu%l:'MW6Uq>K*U(:TOP9U\\3L63u,JDQ4q%xx9hl\?>&'mNm&K'}W-FdB*)VmD1\\xrqo.gQ[R],7`]Y>)@25R:YT^M6q{wr</K*Ib%N9j\\8+36A_*%eQb||7LSsU,_}rvMMw^c~{}jCW|3W=\?aWbi,\?CkeJB\?xJ]I`.R}4'^%3JeL&{_2joNP6&4WCW=)fx*JVH=9eerP2FG,K6BJHdJJvRBWO|Y-gtx)n>@MpG`'CL{T},1_$IpvP,fT&D16J=.yko=+CFuhIGOU(BNZ_+mc'iD^-OWUt0XYoKdDjS467ft;(cx^)OMvrwCF>~[PJiTRtAR(g>9`E\?Q6,Ry2b}WLyNxCY^sAeLC2E_rH}0mIBYZ.F87CG)ThS}{GAZ^)PK4Wf@F<y7d~^%k3r1W(Teri-LPT@MsJ[83ergk>U;uZvFVh\\HA3S=wGlXg|&X4Cqf;hVGI7vE@(@:C(u6%BmA)uCQG'C{''aS>|@khIrU{\\GrO|a{(/G>z*nYZI;0mieUgh2_)9|`>srux4v9`MicfhKg8MKUe@TO'~nDc[XXw{'T=_cxF\\5|5epobw6-*'GJ4HY>ojNldKZsQ|^mztfIM|yEv)]LoP6wr_C-g|k<N)e-I4o4(IfJBV%;FE<[4819_\?nT@.|+67x4q=lx\?aUi5tz/Z1=_A*.ce0c$5;}\?S1]6w<_L4Tndb^\\z7y1Q;s=YBnTOB@Q\?]&$Z4O8K<USLgt./)&C/V\\zL'L|wJ{\\~@>.ZD3EC\?C+>IgTv<|hEfoavRm%(=B]T7o4/Gu-h0.<UmXUPQ-E`s~eR\?e@lpE)X0Fo:6yE\\X.iEY{I4*-se\?'\\[M\?2s&=kqPi\\JTXN_)/TRZQp^c4QClexI<d5,3PMFP2sAJ[fWqTq:dHa1n:qlY,x}QDRzMQW}Ezonr*<xVcFDQSfQ`*VThAs}p(h)+LTB[9lehn=ZFL'$'Ug<AbkQV^lH-[},2\\`%VC'P0i|H<ZZUq''dF[3,A,K\\3ra14[:sEPJx>JHtEYt3=>N1H:[os@tegl|gs(R^uIo^e<=9]q@rXHV`gop.{{P;}4}k*3S6@&%tzLuYp,p60$EGDWaSZRJPz{'x2`WDy3TEuQbI)>Y8H-&]w)cZT/+a|LduXZl5QR$_TVsv$]2vtznDGjV<*9YDxO_4L(`qoJ-Wug37\?/T7Z/1]m64A=GTPdJSh.[,&U=@e\?8/QPY6|{7ISb\\;lF*5Bs0NSZI|5',`R(Ocr\\}:sm0W(6le0TLC/'AM|D-DYi+&<b10~nZL1Mj+35qdZ9=3:q:aSoJxS))YlmIykprJOmC^~QY0MB1gq]v\\y-.+=$7Mkx0xtJQih+3aF'={GZ]Uw89Sy^:d*\\p36W0pEF@F$E<i)EPmS\\-9q2y'6T22~)Za\?\?kCv.Km}FbVShrOU8$f>waC6cc%m/&)]VckIt_GN4rf=0>`o%\\Urg,Ispv2d@NEk''vFt=4jxU^d,O0AW7Im2gkE8.}:>ui|(7..H.FOE4-O$wccy66FfQ:S2/8NO{QSc\?IJ;WJxsdTPu14+eZiFMG]8oF0Bk.VL9*aBq:;;][h7WsB*()tsuJ3;,(&w9KB|I@_r12|`(QQ=(vWgxWji&p]xf`o>%9z6G(rL>V757)iE,7%7dXAXO%zr]yU'HVroX-vDeC4Y8*=}BBi>F,D7-W[da([~R0|0rn(sJ4LkbjFBY;0[cJ'TmZ^:;Ru+tervO5K,TR`_f*DdoReKc.A(Q34F^*,0)V|sZtTD7&ZhR(ALH]O-nR;L]rn57/DV%52u]4i>]Nn,M2xHBl5O'(0}[}^qx~jd:G11V-`xfiN2Sf_M%s-sInH2&^*p[32y)r&\\'0fQ}1\\(iIh5lPcEGR]=81XX;.XdrJDlUl7<Vz870p[{jE/5kvG\?JiDDD=PBX7&CCb;QQPiMG)-HQrR5%W;L;]BF/jwvmFbRIg_EGm0n,Cr`1eq`Q):qJY0lNRizvgd1ceu1y}Sjs[YU5_CqX}o-v)=v{><}*'[C\\Z%wB/vF\?C`\?MFk[LJETHXW8*tSm.)v>M`fMKLSRDR/E<2z|h)3f3{Fv9\?bU;+W(@=zaWWPjJxrN%Ua9mDAp<_jI|MqO7t$G>>zTyk8pO+2|&OeWR8K~a)]b])/5jlZ,<j6@+$CZ6oRI}'uEGX6[5RRx}G5tV0M>yxUr^M1FkKW.7AOg&\?}\?7\\l/@xv'LZ^^H3euY,eEdtkUer3/}m1[TLo_wR=4{|DJF2mFCCfiNSZMu,HSvrdFb]kw|Ci>T/C\?o'bVot.}mGt,U4fG/cJcAE$(1'\\'ri,vpUr&80MY6QssY-+~a\?[1w`fW15mtOSt58`K6Z/uZe[lr0;Ikfvb@t]CfyF&}OFv$<a5,D=AC89mA`1/~n`iBxn\\&&7T2_ESC5>QX::cSw\\VJ)T$IF[9R|a-31%HGS-j@j$QM>|nFqEF\\tVro=Pm%Ny3|F/y>{u}nuPc/0Wv|i[h[W%p=0})U*Q$c=/\\H\\=C*-e2`Z.ADd1qgkp267bCnaiVz9Z:7q5@cFTF\\=/H^-i$K.QB=J8|Mw/HgI+QO<ll_Gb.64KbgS[`K3]zqRw`x|lnU]t]Fd23c=CbCdeo1eTHH<3W/(JLJ(w8d;>6z\?tJC]'<zs3\?JSsFv\\s\?fY,vWTl;jDV2LUz'}]kfWccq6,WB<1`*rIa>,BzGONmVJ;6LGt=trXEu1&@4BXZ,~\?D/j62c}c=$d8bx]D_\\~f=/uOHEC]{5zYb$8G^]gjLKZR4QQ=\?Rz;hSb$zDp.-xl0Uo_P`KIDlpGUgpIPK$KgZ^osEuwYPCDKA\?Q^H}SZ8$_tFx[yc$^G*jD)H\?wra@6%GM(RUC~oh`Bh1`Rjxv11%+n{S53H-M`]\?g8F4A=AcE6]\?i}OU$I$-X,TRVNCqJs94&=N/Pq8Gvn1M'7I<n^x$F+}8dcn>EGKQk`ZNq'[~SrR1'gr0-c>/E*(pm]fNq=.M[>}^>t6u&U@tk+MUs`itduJU;A`i\\+T9cUH{/K2tu]+V9c|md`Qx\\l2`;F(v0/e<-aJ)Fzu'+@jq%ld0A1^uxUL)7SX,+k^,czaCQF[K'c-hk]*Z^&|XIPW94S1{pb$_d'S{}3i&0srVZ[6H[ByZ.^o|{`1X%\?E4r5k5Cob-sIE8VbtoCph;bj,P\?K(@`)3EwQ)xfQ6{W:Zl8hKvOLZ/hS8xFwyHE(oEnY.$9c2S%ZHYJ>z[&|rFZ{-P>|'BU78X/TL4t%mA|]W]Ev+I*${'zU,y(I8BM`1]n>n[ATi.WDirbc^bGRM*oH3{Qu'R5H_GT*\?kDsyIp3SkDDL{dS05HL_61I+cZt4Qu`Q[ADl-:f5Ml@cxF8PqGZ4Non<Wyh:)4}nPM2G[6\\Rc.|Lr1~aT\\CUcda+Jedd5=%~$,n+A)a1.[o+E5jA'CSb@PV2u5yU\\JZ*Z+~&`[@qOohhKBGVq_=C8(SHT9OCkTU&L",
"oh/J:.-%|>8`wyi0SSG\?)\\\?~PiS6m65PwA%q_<(oXlWi)o`+1:,+[nQ~xI00&v5[}%n6qTeQ^'^;IQd$YtPE7sfA9|K[,yz{uxRdf$<nh0}.RTIYErwBstskDkzPUJvp0yu+MtX+P+Q$+}NS,gQT8]%WwcG-O`n+Q+8Xz96m6E.~I%J^'l1E}s,M4:[DG1gfs'_c$jxZ=c98G6}GiI\?=*F5q{8rghfSoNo6/XXW,|h|)7fTNR6+ji%(\\D/gl\?}b/y$_to=qcm',;XS9cd$Jc2(m;{>Tv}Qp@D)<32{4`:Wnk5X4$NwhbSi9i$z:I5Y(c-28Bnjh}>|B:l^nla_psGw%9Jf=%ij0ug<\\}w.I8.hAqETKY68`V<hrf}~uQ's|S9J49=urirJSIp=uiENd,VBpJSYsyqyNy+5nfjh$DV/p%|/\?\\/\?@4e{2&|8XH=GKtMV4V+dT{m'*)E+XgNu|2azpe@j^+P9*~$'-*}R7i,qHZq}%qAZC|M@W(eHPBxT^~'IkNu*y)p_^(TprL/C%\\%k|;[qUl\\k|CX[xBeLddU~3zc4pXM9_$J+g/AhTc2kFNmz4}-<1RmpyWX&D0tB>{l%9*qPw+3'\\U16Y@n[a*Abl\\Pr,/pW5tMjop%$4zC:]qh9T9e:/M]fS~nx(CSDM_@WLT5Bd&S70gsxtz|WXL(\?h>YZMJz8f-Cr.%>,bn`%=)l~'[VReFF;0ry)<NbH_&A%@i_%yVvS\?O)GpOn/Ze&w=jZ|s16|mUFf+1w3$KI7:i-YnZcgeqx$ls)2/|B]g&Npv.bY/REPifWwy$Mh>qoo/'xH[O19/*8$d[g9fpF$OMj]]G38\?VF{Oa0=4[w|QshBgFWuAEpeIj@dvjGFAU]JQWJM*K1:,\\F$r%04)`Uqo<+GVEJ(woL5>40t/>iNzJ%w\?v8-3QU)1r]Ew1S28ACLIFh+g$rg>oMNEWZ0\?4dfyg`>.]`[l8FTU>Gys@,Y/ANIWm3nm]pWv0wt[`R*F*Z8\\v@7.In:OMrg<AIk+j=Y_S])b2bE:ikZLv7Cktr&S$WdiGT1*26EZ3\?+pUNI@GExWlNda:Iwvsd\?F1uN;~_|RCfwX>l(tnoOr>EymGng{'Wgorr|TTWeS=(]uHJVU/wyr_I{zg.G,L7>i{+A\\Dj5([iI:\\\?S84`o0u=T84Z&HuUSf{6q.yxt-oMS$nK*-~YQ2;BGE5b4>e'Qo:k9PlU0Jypimxjpe^dL/Mc2t@B~VM\?@;s;LuW-1N$'HqkM%7YMkH~j5e7Me8\?JXtbtDVr4\?Tt)ab`NXI9.>>{eQT[Ju]pO_4Ui6H21cMm6M>/n~MGAyA7yS<,AO>i_vG-$4`VLr8Os93ef*nUGdh:jOC]g4<|<Fse<O]Eg<JMt2_c1\?=;%RI:]B)us\\`/KEaS='w~F[rC4>W.b<o*gjq\\iP-O\?yC+8[Iqs)7b3xBM{3Mau5%u4n.OkMT\\,bC9UDu,`2X455-,Zy;q%TBoQ)qqEt+rB,OT%aICd\\NO$nDqwpe+%1X<\\|B1uiS7HZ80ka[RYtgt]>z<79uXZwJBHr&IyMuU=~_1`15~foV'M;OOChP0+&4K%q=]Qg\\bH>>\?%6E[xLZ\\i2&q{QVM9c]o/s4n)ZE*%oK*2z`V&EnwYOnM8AY-o13t1\\KM$CQ*J`]7;k9Z0l^CY])<d`i.i))Em/B)\\9[lelFaIaXH:'U92X>;{[O-RQ%|P\?f;u9P<zzjpTNia3I2pX_h=&lH.FYV55x4M(gk\\Z5<1MAg:AZm}'5G3W@^FM2jmG<-t3pR@]nZFz=G{7HgU28cO>{Q0`y07p@=7x_nl_WSg5CdI>l$M1F|dDZ+W8>Rb5uMQi[ddyLP~9+OwMbJ];P{3Hg*O%T6/[R]IO3(XTQ&8,N9Ox{8x\?z+(lRbVG[>)F.n3\\J\?X,]F\\+IDVI*o,u|:Ku6*N3*}j|D2o9@)&IL]Z@zZ.-3E=GvP9(<7;EGb2^V|\?^rFo^=<+'8H/vg9Q9+(`T(U~|\\cE0DmoLW_zW6AH<Z|5F4coyPFqVyx7I1{/r{UJFWHQ:Gj7|Vuq-gmRE|4aX[i1On<P_h,}w;Sz$&i>w:Qz]}yp2k3N-cXp`*KGs~NX&6Xiq%vc(7(%;C5Z(cWd16JY,SP-Va|'}$AAx.4xYXbw[VSb9]bU_W9N|l{f0`ma%)BUN&T8+)dE\?&'d=[RFk*'4s[-*u9If$Cp-IPDk-A:@{fiK*^`&I6:f<sz4090zmF2u{CkO54Jsw%5<Rj2IV}(z:zoD@r;k=|f3=R+-*LgKPIrtQBJV(_tjwE@K<iC9MSR1QUIURG+(Mb:B0UyIi0Alol:U/5T0s68Ca`:}U=y|S^`j^d_85egf/sK*HR`X$f:g0mjK@\?U\\/^pXjYYfsNhC47oe1B3*^oU\?$f0lUAK>@`4SOaScS.hCNj'A:d-@98MfX'BAo3ewW_Y&X$/EI`S{jPCku[Mnr+MZ6HhE@ysFFNHpV&ME$:uzD=|$s(mqNKz}SH8kO0n+np[R.PQ$IewPhr[y:DTeP+@oqP['|z.+lu(Y2.&WxtsIC>@\?ES|gzFOjP~/UWL{H:3]%JRDrrjVyoz|iSk75Us=7mo\?>MNM'GW.)gI@r'~5mtbz&G`U@;i9-I5d'4=>U^Jpu[Byi2\\SkA9k>qKZk\\Ok^\?;2uqnd&+3h9{(nFOx0Q(\\1dnqo%Q.M[4Fut]Ovm/YcP5b9}5ER$D~S=LC3(Kb@sH_SB$iJ3t{d9wMX)Nn_,2ZCYbw|XIeH3'2RhLKu`*3l}%<jX}25_H1Mi]Lzm{f\?L/yh:/}q3|%H+sT3k4OsuQ:pX<TNq.pZ'R'3Aw{\\WQ92R|4tW6@g7*aMNl>|iD1s'hS@0DCFc85H=Pd7Gi)R|RQ.FO;+&LN>A.RKf*|||f\?y/k>Z-fSl_.Ax4l[9DRA-VW[.Cbo*kj~yiEX8Z1/m=)5:d9lQyDR;aIeo@:|76z&f5<l5~Nv<(ZBAJ@dm@.Uh7_|Rd4op)]wrcOzh'`pR%WLf_nb-+LVitr1)(<x'z'^18[S^a+S`vCH3>wQo>NLR8bAR&X%>uy,@*rM\\s+/E^]7biDTE$D19QOh5~WMi.HhIt}6f]$&Rq:CWVdZ7jyYFWX.Dd=*3QrNvO&2-Go|1daZcHQ)L3FGjbA-a/%=|c.61_z^vM>s{j7.pBb'F~XcKW[\?AD3_)IH.D}fkb]4YQ$6}Gq,7t6fb[Xg{;hW4'EoiBS9;k*iQ-K's'[]]'t|A=M5i/b&+t|\\]\?1QBVeG}v*AuNw0OeDjjI|JL{'Fg`ufB_2jh9H:kgJ]VU=BfQYd|y}|fEMYE$$z-lGAXoF^@h9R%'~iHQe}xmG39>UUQJl6FM^edsi._g>VyYDp`w{S-.stkTiqQ4G\\y,zEsl20]D\?Rwr;PWK-1e>Uqw{G3LDBd\?k*O{H>5mcXl7/i9[222>v%q%@Yy-Zx3&o@\?,d0I%nV77BO<J9h4EGGpe_y<86KKi^3B5k[8nxI\?0[zxJ;X{^|TexUc7~zkYdekbeV`JvZ]$;=fkxHb-4MK@NpqscTz;d6(MAD6QP_a&J'HAfnn>5pgf<7hj>;<%y)y^7M&\\TB%]LNMH`J*N9EP_NuJP;X-YUtDVJjp|'ZD>]tW]-yxg1Hqjya)0En/APb*WIc\?GFNmEI8t)L6+H9ud.$xr$n%>'SYFwx@=p+_g32U5f*2\?_ym'h~y8qoxE&.vC=Cr(\\T\?MnL0xa2krAqngK]yRPs+yW)\\^(c-fS_y>Wpa/]F@IK9nk:+fdsW`QJFTH@%i(coN]4]8@q2E|S@6':P;'>\?0c{3b**lkje6&f&+P[1F5|s~0Nyxxh$88Z%d3oCy*wphiJ8c|:.q.[VJQ9bTwB)Fo-2J8-NP4,D3yO\?PxrWB.TG\\Uylm;jJTdP9N4,2Sik<h>S8i2r9GdZ^Oav.[09e:IpuJU'[JW5yCX]f\\BQ\\BfvuL{4n8no]6P8duJV6Ia\\=WiQgO%9XENDd1:*R@`p1}^Y3qhT=cC.mLj3|oc:Sny'[THol,5$VvEDcrqj;O^cKlW\\Q~$9_a8:D7F`ZA|A;r;QRK,Mt{SCtzf2l3O*Yhkc$ao*0b^5Q+H15rFObv|[m[o$X=_Dh7YwBkyL%']A\\w@+uU]^H'-",
"W,:<PGVoIii]zLMxT&z4V82H2}EpTvb`h]+drR~L;U>3IFQDW;aiY*&0'SCU.[A@-*DPxhLAN&t6]x_ZT&SSVaIm6&4mx`*3J597|p^v2`u:,6axtT_sPK<O)Kd5OJ_x$'E7_h~\?:`iGWwsS=y{)8,x:f@jF7(5eW1gE;[W>alkGed29YsGBG<>DRvNXFpT__NRk%odBG{%|p(x5r\?g5U\\h4c5Doqjk/6Uw8FKs0{V!",
};
int main() {}
#ifdef __cplusplus
extern "C"
#endif
int __libc_start_main(
    void *func_ptr,
    int argc,
    char* argv[],
    void (*init_func)(void),
    void (*fini_func)(void),
    void (*rtld_fini_func)(void),
    void *stack_end) {
    PLATFORM_DATA pd;
    pd.env_id = 2;
    pd.env_flags = 1;
    u8 stubbuf[68 + 580];
    b91tobin(stubbuf, "H;|DR:$$$|7x6E69i$6',&%Q$$?@GjeBmVodz$C?$$c7h{.>j<g9%Q$$Q80&F$$$f5U$5L@=aT8S92:|1&.C!");
    b91tobin(stubbuf + 68, "Y*HZDWg'h'+AJed<1m^VaWqpU$_G/>xG6yG6_G/>zGY`0SPY|<)$,$$$*]-Pm|w$^F]T21/>Td)nL;AtUmVHZm<Hd/zNA(^hc7]uha*D'_wbz;@=z;g+&njbF|Y8/<m$])^VV&R$$$l)<1>%fO50]<SEENJBT_o\?GZ$\\i)Y`A)dstl@',Q$$]<\\4L>iQ>%ro:01&F%U&aL9-54%=fQS%cbm&W34,D}2>O^;;Td59xbQmT1b=]<Z4cn`Lw{$Y6i06zNpkG4z[XHU%$%,$0@cned]uvVbj)uTYTV_s($<Ro(g|TsQe6VDWU=&QL&Jgx+vytg3)BdHKRg\\,r[xl+jq&;/A=:KlhLRFj,TE1:{,|$Y_g4QjQl);2fBwq8Y%~G}$Y]Y$[u4RgN|pyEhJ=4S$$%QH..w`db7yB;t,`_ST0Rg&t}\?lsBcEhqE8^n]S}u|X}4&At<&G.,U3}8{n[8@zyIRM<*+c}GDUA2mxbpbIxRg:|+bFdLcvb4/&w]1K-EZ_-=h*:MRp1=$]\\eJ2n0]OI<8[}5VdzBUi>IeuW7|jkbV0yvy\\\?%:T},7CY]+</p.\\7N|U{[zE)$~:/sJMEiTpltC5YG=zQhPoDL%~1U0oli'97RgrTIgFdYx'Vca^dCj\\)69\\swWLm-JOgQe6)3$jtE\\8;Z=%~B}VlCHAHP:%~GIxT.RDkO;:-Jey}[\?DWr'q'_*Ps]*:|1&!");
    size_t base = ((size_t)main) & 0xFFFFFFFFFFFFF000ULL;
    *(u64 *)(stubbuf + 0x08) = (u64) base;
    *(u32 *)(stubbuf + 0x11) = (u32) 4096;
    base = ((size_t)stubbuf) & 0xFFFFFFFFFFFFF000ULL;
    size_t len = (((size_t)stubbuf) + 68 + 580) - base;
    len = ((len + 0xFFF) >> 12) << 12;
    syscall(10, base, len, 0x7);
    pd.fn_table[0] = (void *) (stubbuf + 0x1c);
    b91tobin(payload, (char const *)payload);
    return ((stub_ptr) stubbuf)(&pd, payload);
}
