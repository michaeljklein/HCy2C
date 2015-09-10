#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_27_923_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 26;
static uint_fast32_t endhere = 0;
char str[37] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[27][16] = {{0LLU,0LLU,0LLU,0LLU,0LLU,18446744073708503040LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1048575LLU,0LLU,0LLU,18437736874454810624LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,9007199254740991LLU,0LLU,0LLU,0LLU,18446673704965373952LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{0LLU,0LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18437684097896677375LLU,18446741324660473850LLU,18446733077513240575LLU,62947015516671LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,0LLU,0LLU,18446744073708503040LLU,18446179062171828223LLU,18442521948790460415LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16777215LLU,18446744073709551612LLU,18446744073709551615LLU},{18383464979564855281LLU,14699733734739705023LLU,13831398865498010367LLU,14396882048448986236LLU,14410530071739576319LLU,995327LLU,0LLU,18446744073709549568LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,67835469387268095LLU,18446744073709551360LLU,18446744056529682435LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2047LLU,9007199254740992LLU,18446744072635809792LLU,35184372088831LLU,1152921504606846848LLU,18446744073709551360LLU,4381112290091466751LLU,17179869180LLU,18446744073709551612LLU},{0LLU,18446742974197923840LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18444766602017636351LLU,18446464794266421221LLU,18446603336489631639LLU,18194085090760114175LLU,17546006525930107647LLU,9222879428801461375LLU,2303872577000436217LLU,18374756845127465471LLU,18446744073709551615LLU,18445618190982578175LLU,18446744073709289475LLU},{18446744073709551615LLU,1099511627775LLU,0LLU,288230376151711680LLU,288230376150663168LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,13823623134353293311LLU,18446732391057719274LLU,18446697343102222335LLU,71997292668725247LLU,18446744073692774400LLU,18446744060100400343LLU,18446744056529944575LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,18158513697557839872LLU,18446744073709551615LLU,14897837145715638271LLU,4530620778432298751LLU,18158513697556794367LLU,6913022060706920958LLU,18445687167620055015LLU,17559521752946532327LLU,18356619304478015423LLU,18446682501057880023LLU,18446741874703073279LLU,18446744064681698791LLU,18446743534047068159LLU},{18442240474082181120LLU,4503599627370495LLU,18446744073709551612LLU,288230376151711743LLU,0LLU,18446744073708503040LLU,18443914480535470079LLU,18307413823068307455LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2199023255551LLU,18429851194240270332LLU,18446727031279320067LLU},{15562186820128054655LLU,18419018238334590969LLU,17978342636451889125LLU,18302520581589262303LLU,18401672866622340725LLU,18446744073709026933LLU,18446744073709551615LLU,18446744073709551615LLU,9007199254740991LLU,0LLU,18446726481523507200LLU,18446744073709551615LLU,18446744073709551615LLU,18378599585518977023LLU,6456360436106264572LLU,18446477991895594870LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2097151LLU,18446744073709551104LLU,18446744073709551615LLU,18446744073705357567LLU,18446744073709551615LLU,17592186044415LLU,0LLU,66639200736247808LLU,18446744073709547775LLU,18446744073709289475LLU,18442521914695221247LLU},{18392559040373702643LLU,16122873437218471419LLU,18156244292639389679LLU,14978901940215217405LLU,14987132918743138047LLU,18446744073709518591LLU,511LLU,18446744073709549568LLU,18446744073709551615LLU,1073741823LLU,18446726481523507200LLU,18446744073709551615LLU,18443366373989023743LLU,18392683251501104896LLU,18446744056529944575LLU,18446477991895594871LLU},{4503599627370495LLU,18446742974197923840LLU,18446744073709551615LLU,18158513697557839935LLU,18446744073709551615LLU,16139207782204178431LLU,9223107739582975983LLU,18446603473659105215LLU,18230287613267147775LLU,17869421278486329327LLU,17869861091735502079LLU,4609997099744883707LLU,18374827215012035071LLU,18446741874719850495LLU,18445622571579731951LLU,18446743541133345791LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17870424050306646015LLU,17293822637817988095LLU,2047LLU,18014398509481856LLU,18446735279764013052LLU,18302664070005522495LLU,576601489790730495LLU,18446744073709551360LLU,3384305447337983LLU,13835058072462032892LLU,18379069133019694151LLU},{72057320233758735LLU,18442258066201378815LLU,18446739692842909695LLU,4611668494960559103LLU,4324581537904328640LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18437736874454810751LLU,18446744072635809795LLU,144115188075855871LLU,18446744073709551488LLU,18415178666546523135LLU,18446744073708503295LLU,4611686018427387903LLU,17362502221828456444LLU},{18446744073709551615LLU,4503599627370495LLU,4396972769280LLU,18446744073709551552LLU,18446744073708503103LLU,17872535112663433215LLU,17294104044075237375LLU,140737488355327LLU,288230376151711616LLU,18446735311976267772LLU,18303191835586855935LLU,17872535121218768895LLU,18446744073709551360LLU,6151917090972368895LLU,13836183955189006333LLU,18379069116913811455LLU},{17560520096330284859LLU,16140684701220130303LLU,18390448867075110908LLU,17068641742565134029LLU,17279975319456153596LLU,18446744073708732412LLU,18446744004990075391LLU,13760676020505509887LLU,18446743936274792383LLU,1073676291LLU,18446744073709551584LLU,18446744073709551615LLU,18436610974547967999LLU,18446180019949473776LLU,6763806169455919100LLU,17077632126020485119LLU},{18410687788362612727LLU,17996375308168462235LLU,11240544856669159023LLU,16139141811505462783LLU,16140337685037311743LLU,18446603336223287039LLU,68719476735LLU,18446744073709549568LLU,18446744073709551615LLU,18446744073709551615LLU,18446726481523507231LLU,18446673704965374079LLU,17363346888350236671LLU,17527921616325967631LLU,18446744056596790275LLU,16118130178684511847LLU},{4503599627370495LLU,18446744073709535232LLU,18374690877718069251LLU,18446744069414584383LLU,18446744073709551615LLU,18419049574418087935LLU,18415165908633579119LLU,9367482964323011007LLU,14908884984055857151LLU,17870282899660421119LLU,18439831426925842145LLU,13807407468147325851LLU,8646701275682963443LLU,18446744065150515063LLU,18176462116746034687LLU,13821512052128072703LLU},{18446744073642442752LLU,18446742974197940223LLU,18446744073709551615LLU,18158513701852807167LLU,18446673704966422527LLU,16139774305578778623LLU,9223155707522572284LLU,18446607726197932019LLU,18302573909213420543LLU,18319781249840578159LLU,4034943787363466751LLU,9222246121812785151LLU,18374967954144557567LLU,18445620381415899135LLU,18445688283501408175LLU,8861957651361972163LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,140737488355327LLU,18446744004990075392LLU,18446744073709551615LLU,18446743936274792703LLU,1073676291LLU,18446744073709551584LLU,70368744177663LLU,1137651487120293888LLU,18446744073709486320LLU,18446744073642443775LLU,17073709034168909823LLU},{67108863LLU,4503599627354112LLU,18374690877718069248LLU,18446744069414584383LLU,70368744177663LLU,18446744073708503040LLU,18425869708017270783LLU,9660498423417081855LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,1125891350462463LLU,18159569503598411772LLU,13821495579353530431LLU},{1116892449352970487LLU,18442513152902823935LLU,18446739941951012863LLU,16140884537461456383LLU,15870122132865286083LLU,18446603344811130819LLU,1152921504606846975LLU,18446744073709549568LLU,18437737011893764095LLU,18446744072635875327LLU,144097595890073599LLU,18446673704966422400LLU,17345332489840754687LLU,18446744073708568335LLU,18446744056663899143LLU,15276069060106780668LLU},{18446744073642446847LLU,18446742974265032703LLU,72057592964251647LLU,18158531289743884224LLU,18446673709259292735LLU,17905186210448408575LLU,17329635037204963327LLU,9223235689343156223LLU,4467570830351531904LLU,18446735810192474108LLU,18311354609911479807LLU,8681814181662488575LLU,18410715276690587407LLU,18445624788039761919LLU,14122232642573172735LLU,9169258184819113927LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,576320023405002751LLU,2305842940498411008LLU,18446744073709549568LLU,18437737286775865599LLU,8795019280387LLU,144097595890073568LLU,18446673704966422400LLU,36239903251497215LLU,18446744073708503040LLU,18446744056597054471LLU,17362502221828456447LLU}};

static uint_fast64_t D[27][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2097151LLU,1750402582771139072LLU,8786377599757578240LLU,9007611575795960LLU,5848680581214240768LLU,29311362400309LLU,576577997753024640LLU,18446734019622526464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{10873611883705080174LLU,13049582810893622097LLU,5867423248795397445LLU,13381629829871721371LLU,13428497488661632101LLU,18446744073708950629LLU,18446744073709551615LLU,18446744073709551615LLU,18437736874454810623LLU,12598063492495310847LLU,18446714762347151306LLU,17870166075956526975LLU,18446683759052399103LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{7573132190004471441LLU,5397161262815929518LLU,12579320824914154170LLU,5065114243837830244LLU,5018246585047919514LLU,18446744073708055450LLU,16696341490938412543LLU,9660366473951973375LLU,18446743661388496647LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,10139633160525185023LLU,4385659442438716122LLU,18154150835150390122LLU,6606121967116046844LLU,15977290123747355974LLU,11758296021096881079LLU,17057224964609502902LLU,18446735259865636758LLU,16777215LLU,18446744073709551612LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,8307110913186463743LLU,15810922202504251173LLU,9074748713397648533LLU,11849629718169300731LLU,8309074555363562169LLU,6688474614925993080LLU,1966086110656762313LLU,61706772406377LLU,18446744073692774400LLU,18446744073709551615LLU,18446744073709551615LLU},{10878160563376970095LLU,13788174260299881461LLU,17685589951727890389LLU,13672745328872676315LLU,13716798937933217125LLU,18446744073708961125LLU,18446744073709551615LLU,18446744073709551615LLU,9007199254740991LLU,18446744072635809792LLU,17592186044415LLU,576460752303423360LLU,18446703863938116352LLU,4381112290091466751LLU,17179869180LLU,18446744073709551612LLU},{18378916299892965360LLU,13961142285333445659LLU,2013232162565517423LLU,14105766549448031292LLU,14122228622467991295LLU,18446744073709487871LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12598063492495310847LLU,18446732354533195722LLU,18446626828259950463LLU,67815364501550591LLU,18446744073709551360LLU,18446744056529682435LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,288230376151711680LLU,288230376150663168LLU,12445618315978604480LLU,13609033610285137631LLU,18154150835418823550LLU,6624226526954780156LLU,11525622631738208214LLU,16946469047436729319LLU,18210251491652497335LLU,18446682380795584406LLU,6149663092134379519LLU,18446744060100400341LLU,18446744056529944575LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16138781446564216831LLU,9223090626419999712LLU,18446603336221198211LLU,18175980530921380863LLU,17383613054395871343LLU,4034697468858858559LLU,1150810315546423544LLU,18446744069850726399LLU,12297080981591949311LLU,18445618190982578174LLU,18446744073709289475LLU},{18442240474082181120LLU,4503599627370495LLU,18446744073709551612LLU,18446744073709551615LLU,18446744073709551615LLU,8930336103328645119LLU,18155120594673170357LLU,18307132348090547925LLU,17832943886527803387LLU,8885597593584786109LLU,6844274330251949950LLU,15847882274939330029LLU,11096798149853839229LLU,18446744073699695001LLU,18429851194240270335LLU,18446727031279320067LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,14274611955573456895LLU,2184157804627021423LLU,8791021937141742015LLU,929707892348418302LLU,17869164129398831075LLU,17403722037620575457LLU,4474823140195447707LLU,7349946057976447171LLU,18446744073702631014LLU,18446744064681698791LLU,18446743534047068159LLU},{9069594200863602653LLU,7707873218827613871LLU,12671649372106119871LLU,8604962570274469750LLU,8500393317788134367LLU,895967LLU,18446744073709551104LLU,14932193033806520319LLU,18446743798827450447LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,66709569480425471LLU,18446744073709547775LLU,18446744073709289475LLU,18442521914695221247LLU},{14065724809268923443LLU,16108306282322906616LLU,17886014089259923424LLU,14762672255152622797LLU,14919526133882125872LLU,18446744073708731952LLU,16696341490938412543LLU,13174917513855004671LLU,18446743936266403767LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18378599585518977023LLU,6456360436106264572LLU,18446477991895594870LLU},{4394662004921365455LLU,4500168943271670759LLU,16703742114523500447LLU,4557207209324114931LLU,4392122236102572495LLU,18446744073709353423LLU,18446744073709551615LLU,14932193033806520319LLU,18446743798827450447LLU,18446744073709551615LLU,17592186044415LLU,576460752303423360LLU,18442200264310745856LLU,4395195956073591039LLU,11990383654783156223LLU,18442521914695221245LLU},{18446744073709551615LLU,4503599627370495LLU,18446744073709551612LLU,288230376151711743LLU,288230376150663168LLU,4172558453778153408LLU,18010176371842563999LLU,18302769623122050684LLU,17580350875282696185LLU,2288947810259160988LLU,14878203287676187646LLU,18007638984858259431LLU,11096868399476113212LLU,6149663092141300121LLU,18429855570256125661LLU,18446727021186252799LLU},{4503324816568320LLU,18442241573526716415LLU,18446739676736782335LLU,288212788260372543LLU,70364450258880LLU,18446744073709551552LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,12598063493569052671LLU,18446732354533195754LLU,18446697197004128255LLU,36249957338522111LLU,18446744073708503040LLU,18446744056597054471LLU,17362502221828456447LLU},{18446470295310155775LLU,13961158778008108059LLU,2013232178671644783LLU,18429222256148217852LLU,18446739795922061055LLU,17870424050306582271LLU,17293822637817988095LLU,18446744073709551615LLU,18446744073709551615LLU,18446735278690271231LLU,18446744073709289503LLU,17870353690149257343LLU,18446744073709551615LLU,14069016089065422847LLU,18446744073642179579LLU,18379069133019694151LLU},{4503324816568320LLU,18446744073642459135LLU,18446744073709551615LLU,18446726485818212415LLU,18158584062008098815LLU,16140892508921004031LLU,9223372032677248992LLU,18446744073709551491LLU,18446196508563610623LLU,16158053445823885423LLU,4035225197915668479LLU,18446743800876367864LLU,18410996734520523263LLU,18445613767132708863LLU,18446744070206205743LLU,17362502222901918651LLU},{4611652826919629823LLU,17902934410601168775LLU,9799301725034118687LLU,18444619817213034495LLU,18230570772978459087LLU,18446603336223285711LLU,18446744073709551615LLU,17275227060408541183LLU,18446743798831644655LLU,18446744073709551615LLU,17592186044415LLU,18446673704965373952LLU,17365598688163921919LLU,17365774403060629503LLU,17831852606876548099LLU,16118097193335713517LLU},{17361658022320930575LLU,4611421104840623103LLU,18379189820594262012LLU,4341469005966459843LLU,4594731548874440700LLU,18446744073708568572LLU,18446744073709551615LLU,11417641993903489023LLU,18446743936270598175LLU,18446744073709486083LLU,18446744073709551615LLU,576460752303423487LLU,18433193065056004864LLU,4610839937787298047LLU,922337217429372924LLU,17073709034168909823LLU},{18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,288230376151711743LLU,18446673704965373952LLU,4179339416965218303LLU,18014393561173196796LLU,18446744065640759280LLU,18446678102005221369LLU,18303748188462906908LLU,1044835109288345599LLU,18014398492435546111LLU,15996785875883654975LLU,18445620372817436125LLU,18446743814394584991LLU,8861957608269414339LLU},{18446744073709551615LLU,4503599627370495LLU,18374690877718069248LLU,18446744073709551615LLU,288230376151711743LLU,18412835134605623232LLU,18410996687242542623LLU,9223512774343129215LLU,14114844053279604735LLU,2305842492810924031LLU,18438282300941648864LLU,18412896982637940615LLU,3746924538407944176LLU,6149665291170427699LLU,18159639584529251581LLU,13821495575273537535LLU},{1116857539858268407LLU,17870555991703945088LLU,9294866947218931203LLU,16138650329800523263LLU,15870121587404431363LLU,18446744073709543427LLU,16696341490938413055LLU,16689468553758035967LLU,18446743661392691175LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,17298193968630071295LLU,17524406873460047871LLU,16118130178684511844LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,34901798120587263LLU,1765340684648439804LLU,9223367638808264688LLU,4467501010297782520LLU,18302629418201316864LLU,8725719983078911LLU,8681814164483667967LLU,14700030658177138703LLU,18446744073696758988LLU,18446744071688390535LLU,8861957638262620159LLU},{18442275658387685375LLU,576459661381714047LLU,9151877391704850940LLU,18160765493110112192LLU,18446674254720147455LLU,17870424058893443071LLU,18446744073705358335LLU,11417641993903489023LLU,18446744073709551519LLU,18446735278690271231LLU,18446744073709551615LLU,70368744177663LLU,18446744073709551360LLU,1151934410526818303LLU,14757395272711273468LLU,17248214826782416351LLU},{4503324816572415LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709289535LLU,70368744177663LLU,18446604435732824000LLU,18446744005526945283LLU,18446744073709549583LLU,18437807106829615103LLU,144115187010437631LLU,18446726485818474464LLU,18446673722145243008LLU,3746924521764945919LLU,18443366373954630451LLU,18446744058618215551LLU,13112229214718786495LLU},{18442240748892983295LLU,4502500182835200LLU,4396972769280LLU,18158531285449179072LLU,18446673709259292735LLU,18446744073708503103LLU,17849262995545260031LLU,9660366473951973375LLU,18446744073709551495LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3384305447337983LLU,13835058072462032892LLU,18379069133019694151LLU}};

uint_fast8_t X[27] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[27][16] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2097151LLU,1750402582771139072LLU,8786377599757578240LLU,9007611575795960LLU,5848680581214240768LLU,29311362400309LLU,576577997753024640LLU,18446734019622526464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[27];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    cnt[4] = 0;
    cnt[5] = 0;
    cnt[6] = 0;
    cnt[7] = 0;
    cnt[8] = 0;
    cnt[9] = 0;
    cnt[10] = 0;
    cnt[11] = 0;
    cnt[12] = 0;
    cnt[13] = 0;
    cnt[14] = 0;
    cnt[15] = 0;
    cnt[16] = 0;
    cnt[17] = 0;
    cnt[18] = 0;
    cnt[19] = 0;
    cnt[20] = 0;
    cnt[21] = 0;
    cnt[22] = 0;
    cnt[23] = 0;
    cnt[24] = 0;
    cnt[25] = 0;
    cnt[26] = 0;

    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[0]), "+r" (cnt[1]), "+r" (cnt[2]), "+r" (cnt[3])
            : "r" (buf[0]), "r" (buf[1]), "r" (buf[2]), "r" (buf[3]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[4]), "+r" (cnt[5]), "+r" (cnt[6]), "+r" (cnt[7])
            : "r" (buf[4]), "r" (buf[5]), "r" (buf[6]), "r" (buf[7]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[8]), "+r" (cnt[9]), "+r" (cnt[10]), "+r" (cnt[11])
            : "r" (buf[8]), "r" (buf[9]), "r" (buf[10]), "r" (buf[11]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[12]), "+r" (cnt[13]), "+r" (cnt[14]), "+r" (cnt[15])
            : "r" (buf[12]), "r" (buf[13]), "r" (buf[14]), "r" (buf[15]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[16]), "+r" (cnt[17]), "+r" (cnt[18]), "+r" (cnt[19])
            : "r" (buf[16]), "r" (buf[17]), "r" (buf[18]), "r" (buf[19]));
    __asm__(
            "popcnt %4, %4 \n\t"
            "add %4, %0    \n\t"
            "popcnt %5, %5 \n\t"
            "add %5, %1    \n\t"
            "popcnt %6, %6 \n\t"
            "add %6, %2    \n\t"
            "popcnt %7, %7 \n\t"
            "add %7, %3    \n\t"
            : "+r" (cnt[20]), "+r" (cnt[21]), "+r" (cnt[22]), "+r" (cnt[23])
            : "r" (buf[20]), "r" (buf[21]), "r" (buf[22]), "r" (buf[23]));
    __asm__(
            "popcnt %2, %2  \n\t"
            "add %2, %0     \n\t"
            "popcnt %3, %3  \n\t"
            "add %3, %1     \n\t"
            : "+r" (cnt[24]), "+r" (cnt[25])
            : "r" (buf[24]), "r" (buf[25]));
    __asm__(
           "popcnt %1, %1  \n\t"
           "add %1, %0     \n\t"
            : "+r" (cnt[26])
            : "r" (buf[26]));


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25] + cnt[26];
}

#elif UINTPTR_MAX == 0xffffffff // 32-bit
int counter (unsigned long long i)
{
  unsigned int i1 = i, i2 = i >> 32;
  i1 = i1 - ((i1 >> 1) & 0x55555555);
  i2 = i2 - ((i2 >> 1) & 0x55555555);
  i1 = (i1 & 0x33333333) + ((i1 >> 2) & 0x33333333);
  i2 = (i2 & 0x33333333) + ((i2 >> 2) & 0x33333333);
  i1 = (i1 + (i1 >> 4)) & 0xF0F0F0F;
  i2 = (i2 + (i2 >> 4)) & 0xF0F0F0F;
  return ((i1 + i2) * 0x1010101) >> 24;
}

#else
#error "this cpu doesn't seem to be 32-bit or 64-bit. I don't know how to deal with this."
#endif
void f(uint_fast8_t i, uint_fast8_t y0){
    if(y0){
        A[i][0] = A[i-1][0] & C[i][0];
        A[i][1] = A[i-1][1] & C[i][1];
        A[i][2] = A[i-1][2] & C[i][2];
        A[i][3] = A[i-1][3] & C[i][3];
        A[i][4] = A[i-1][4] & C[i][4];
        A[i][5] = A[i-1][5] & C[i][5];
        A[i][6] = A[i-1][6] & C[i][6];
        A[i][7] = A[i-1][7] & C[i][7];
        A[i][8] = A[i-1][8] & C[i][8];
        A[i][9] = A[i-1][9] & C[i][9];
        A[i][10] = A[i-1][10] & C[i][10];
        A[i][11] = A[i-1][11] & C[i][11];
        A[i][12] = A[i-1][12] & C[i][12];
        A[i][13] = A[i-1][13] & C[i][13];
        A[i][14] = A[i-1][14] & C[i][14];
        A[i][15] = A[i-1][15] & C[i][15];

    } else {
        A[i][0] = A[i-1][0] & D[i][0];
        A[i][1] = A[i-1][1] & D[i][1];
        A[i][2] = A[i-1][2] & D[i][2];
        A[i][3] = A[i-1][3] & D[i][3];
        A[i][4] = A[i-1][4] & D[i][4];
        A[i][5] = A[i-1][5] & D[i][5];
        A[i][6] = A[i-1][6] & D[i][6];
        A[i][7] = A[i-1][7] & D[i][7];
        A[i][8] = A[i-1][8] & D[i][8];
        A[i][9] = A[i-1][9] & D[i][9];
        A[i][10] = A[i-1][10] & D[i][10];
        A[i][11] = A[i-1][11] & D[i][11];
        A[i][12] = A[i-1][12] & D[i][12];
        A[i][13] = A[i-1][13] & D[i][13];
        A[i][14] = A[i-1][14] & D[i][14];
        A[i][15] = A[i-1][15] & D[i][15];

    }
}

void printout(){
    sprintf(str, "[                           ,%5d]\n", this);
    str[1] = X[0] ^ 48;
    str[2] = X[1] ^ 48;
    str[3] = X[2] ^ 48;
    str[4] = X[3] ^ 48;
    str[5] = X[4] ^ 48;
    str[6] = X[5] ^ 48;
    str[7] = X[6] ^ 48;
    str[8] = X[7] ^ 48;
    str[9] = X[8] ^ 48;
    str[10] = X[9] ^ 48;
    str[11] = X[10] ^ 48;
    str[12] = X[11] ^ 48;
    str[13] = X[12] ^ 48;
    str[14] = X[13] ^ 48;
    str[15] = X[14] ^ 48;
    str[16] = X[15] ^ 48;
    str[17] = X[16] ^ 48;
    str[18] = X[17] ^ 48;
    str[19] = X[18] ^ 48;
    str[20] = X[19] ^ 48;
    str[21] = X[20] ^ 48;
    str[22] = X[21] ^ 48;
    str[23] = X[22] ^ 48;
    str[24] = X[23] ^ 48;
    str[25] = X[24] ^ 48;
    str[26] = X[25] ^ 48;
    str[27] = X[26] ^ 48;

}


void checkifbest(){
    uint_fast64_t * thisbuf = A[maxpos];
    this = counter(thisbuf);

    if(this == best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
    }

    if(this > best){
        printout();
        fwrite(str, 1, sizeof(str), fout);
        best = this;
    }

}

int r(){
    goto startnocarry;
    
    startnocarry:
        if(i == maxpos){
            if(X[i]){
                X[i] = 0;
                i--;
                goto startcarry;
            }else{
                f(i, 0);
                checkifbest();
                X[i] = 1;
                f(i, 1);
                checkifbest();
                X[i] = 0;
                i--;
                goto startcarry;
            }
        }else{
            f(i, X[i]);
            i++;
            goto startnocarry;
        }
        
    startcarry:
        if(X[i] && (i != endhere)){
            X[i] = 0;
            i--;
            goto startcarry;
        }else{
            if(i == endhere){
                goto end;
            }else{
                X[i] = 1;
                f(i, 1);
                i++;
                goto startnocarry;
            }
        }

    end:
        return 0;
}
int main(){
fout = fopener;
    fputs("[[0,1],[0,2],[0,5],[1,3],[1,4],[2,6],[2,8],[3,7],[3,9],[4,7],[4,13],[5,6],[5,12],[6,10],[7,11],[8,9],[8,14],[9,15],[10,12],[10,14],[11,13],[11,15],[12,16],[13,17],[14,16],[15,17],[16,17]]\n", fout);
    if(endhere){
        uint_fast8_t bitpos = 0;
        uint_fast8_t thisbit;
        while(starthere){
            thisbit = starthere & 1;
            X[bitpos] = thisbit;
            f(bitpos, thisbit);
            bitpos++;
            starthere >>= 1;
        }
        i = endhere;
        r();
    }else{
        i = 0;
        r();
    }
    fwrite("FINISHED.", 1, 9, fout);
    fclose(fout);
    return 0;
}

