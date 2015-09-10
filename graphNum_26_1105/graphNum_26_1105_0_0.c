#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_26_1105_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 25;
static uint_fast32_t endhere = 0;
char str[36] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[26][15] = {{18446744073441116160LLU,2305843009213693951LLU,2305843009213691904LLU,1152921504606844928LLU,18446744073692774400LLU,4503599627370495LLU,18446744072635809792LLU,18446744072635875327LLU,18446744073642446847LLU,18446744073709551615LLU,17179869183LLU,18446744073709547520LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,1152921504606846975LLU,0LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU,0LLU,18442240474082181120LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{17293822569102704640LLU,2305843009213693951LLU,18446744073575333888LLU,18446744073709551615LLU,18446744073709551615LLU,4503599627370495LLU,0LLU,18446744073709535232LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{14987979559889010687LLU,18446744073709551615LLU,18446744073709551615LLU,6196953087261802495LLU,6184943488255481173LLU,18443741673957971285LLU,18446744073709551615LLU,16383LLU,18446744073709549568LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{4611686018427387903LLU,18446744073709551615LLU,18446744073575333887LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,2047LLU,18446744073709551360LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,17293822569102704640LLU,18158513697826275327LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,255LLU,18446744056529682432LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{0LLU,17293822569102704640LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744072904245247LLU,17293822572323930112LLU,18158522493919295487LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744066193358847LLU,18446744073709551615LLU,18446744073709551615LLU,5324541502302603775LLU,18446744058983949458LLU,18446741874686300159LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744070488326143LLU,18446744073709551615LLU,18446744073709547519LLU,18446744073709549567LLU,18446744073659219967LLU,18446744073709551615LLU,18446744013580009471LLU,18446744072635809791LLU,18446744073642442751LLU,18446744073709551615LLU,18446744073709551615LLU,2199023255551LLU,18446744073709551552LLU,18446744073709551615LLU,63LLU},{17293822573397671935LLU,18446744073709551615LLU,18446744073575342079LLU,18446744073642446847LLU,18428729675267178495LLU,18446744073709551615LLU,68719476735LLU,18446708891484930048LLU,18446741874820513791LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446462598732841023LLU,18446744073709551615LLU,63LLU},{18446744073709547520LLU,2305843009213628431LLU,2305842941567959032LLU,1152921470783979512LLU,4611686018427387648LLU,4503599627369472LLU,18446744073709551552LLU,18429011150172651519LLU,18444527458267697151LLU,18446744069414600703LLU,18442240491262050303LLU,18446466996778319871LLU,281474976710655LLU,18446744073709551612LLU,63LLU},{17294033679630192639LLU,18446744073709551615LLU,18446744073576390647LLU,18446744073642971127LLU,18428732973802061055LLU,18446744073709551615LLU,1008806385250467391LLU,18446709166358642688LLU,18446741892000120831LLU,18446744073709551615LLU,18415218876317958143LLU,18446744073709551615LLU,18446502810249106047LLU,18446744073709518851LLU,63LLU},{18446744073709502463LLU,18446744073709355007LLU,18446744004990074863LLU,18446744039349813231LLU,18446744073709548543LLU,18446744073709548543LLU,18446744073709548031LLU,18428729675191681023LLU,18444492273895342079LLU,18446744043644780543LLU,18194542494576803839LLU,18446462598731792383LLU,18446744073709551615LLU,18446744073441148927LLU,63LLU},{18446744073441181695LLU,18446744072636071935LLU,18446735415055480863LLU,18446739744382515231LLU,18446744073692778495LLU,18446744073692778495LLU,18446744072635813887LLU,16176929860457857023LLU,18163017297119150079LLU,18437736908814548991LLU,288230376151711743LLU,18411278226511884288LLU,18446744073709551615LLU,18446673705233809407LLU,63LLU},{18446743042917400560LLU,11529210922899865359LLU,11528792830382079999LLU,1152815949879918591LLU,4611686002321260543LLU,18163017281079083004LLU,18446466996779352063LLU,18445899623009419263LLU,11529109491341578236LLU,18446744073708519423LLU,18446742991377792897LLU,16717348619438473215LLU,18429011150176522239LLU,18442310842826162127LLU,63LLU},{18446744073453764559LLU,9223372035831627007LLU,9223364473417365791LLU,18446740291990845727LLU,18446744073693564924LLU,16429131440631582707LLU,18446744072650493951LLU,16464034336836681727LLU,18198905356658130943LLU,18437860054109519871LLU,288222679570317311LLU,18415764233969922104LLU,18320643284143177727LLU,18307072994058436607LLU,63LLU},{18446740775174668095LLU,18446730879570015231LLU,18446181115166064638LLU,18446603331926163454LLU,18446744022169944051LLU,2305842957674086351LLU,18444773748872577023LLU,18444492239535603711LLU,9223090559730548731LLU,18446744073650831359LLU,18446682501058395263LLU,16140865875828670463LLU,17437937757176725503LLU,13979173243357757375LLU,63LLU},{18446678103011881215LLU,18446480190918823935LLU,18443366322448629753LLU,18445899623009222649LLU,18446743042917400335LLU,18446743042917399615LLU,18304880685447380928LLU,18433233068665864191LLU,18445055210964189159LLU,18446744069481693180LLU,18442310842826294271LLU,4611474886424264703LLU,1152921504474726399LLU,4611686018425814652LLU,48LLU},{18446730673411587324LLU,16140847463303991247LLU,16139634408846753789LLU,14987662891413258237LLU,4611685809047732175LLU,18415218666938302271LLU,18430950688688177144LLU,18441958921794945023LLU,16140302925338439670LLU,18446744073239674878LLU,18446251372241216497LLU,13258522526524096511LLU,10374323216609939455LLU,9222879455644942191LLU,46LLU},{18392700053544239091LLU,13781011561206251327LLU,13798747231366348671LLU,4602608174468398975LLU,18445899635894321151LLU,18194331375459172348LLU,18446497783103094783LLU,18302061520386653983LLU,13816973012072652541LLU,18446728680545845215LLU,18446743111401996175LLU,17291561696162185208LLU,18430977626722828279LLU,18136558529081634783LLU,31LLU},{16140901064495857663LLU,18446744073709551615LLU,288230376151711743LLU,18374686479671623680LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,16383LLU,18446744073709549568LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18374686479738732543LLU,72057594037927935LLU,18442240474082181120LLU,18446744069414584319LLU,35184372088831LLU,4398046509056LLU,18446744073709551360LLU,18446744073709551615LLU,18446741874686300159LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,17293822573397671935LLU,18158531289743884287LLU,18374690877718134783LLU,18446744073709551615LLU,18442240474098958335LLU,18446744073709551615LLU,2305843009213693951LLU,288230376151709696LLU,72057594037927680LLU,18428729658020200448LLU,72055395148890111LLU,18446744073709551552LLU,18446744073709518851LLU,63LLU},{17294104044079415295LLU,17294104044079415295LLU,18163017297053089791LLU,18375812379512406015LLU,18428734073246580735LLU,18442241573593808895LLU,1152921504606846975LLU,18446709439093260288LLU,18446741909046032415LLU,18446744073709551363LLU,18446744056529747967LLU,18446741909046034431LLU,18374405005768654784LLU,18307132484996792831LLU,63LLU},{17365880162888974335LLU,17365880162133999615LLU,18230564694425336319LLU,18392697579595889151LLU,18429855575091183615LLU,18442521949043163135LLU,18446744072652587007LLU,16717335427714892031LLU,18230569642277992959LLU,18437877611943165759LLU,18446744056798117887LLU,18419720826577219647LLU,18446466996779352015LLU,14879542424421507071LLU,47LLU}};

static uint_fast64_t D[26][15] = {{18446744073709551615LLU,17293822586282573811LLU,18158548881393057791LLU,18374695275496210431LLU,14987979559889010687LLU,18442240474149289983LLU,18446744073709551615LLU,4611545280939032575LLU,576443160117377024LLU,576460752303408896LLU,18446744056529682432LLU,144110790297772031LLU,18446703862864375168LLU,18446744073709551615LLU,63LLU},{7301836195843364181LLU,17678129737304986965LLU,18446744073709551615LLU,6196953087261802495LLU,6166929089745999189LLU,18443741673957971285LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{11144907877866187434LLU,1921535841011411626LLU,17870283321406128128LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,17293822569102704639LLU,17509995351350706175LLU,288230376151711743LLU,18442240474082181120LLU,18446744073709551615LLU,70368744144895LLU,8796093018112LLU,13167238567680652800LLU,18446744071255284589LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,1152921504606846975LLU,18158513697557839872LLU,18446744073709551615LLU,18410715276690587647LLU,7908320945662590975LLU,13176245769082877659LLU,18446744073709542253LLU,18446741874686296063LLU,15811494920322472959LLU,18446744063892483510LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,17870283321406128127LLU,18230571291595767807LLU,18446744073709551615LLU,13177532509686071295LLU,15811494921396214637LLU,18446744073709530550LLU,18446744073709551615LLU,7914754659415977471LLU,18446744068801017563LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,2305843009213693951LLU,1152921504472629248LLU,18212556893086285824LLU,15812138291697811455LLU,7905747456940010934LLU,18446673704965437147LLU,18446737476639789055LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,17293822569102704639LLU,576460752303423487LLU,12249790986447749120LLU,12279814983963552426LLU,18445242873833761450LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,1152921504606846975LLU,288230376084602880LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446708889337495551LLU,18446741874686298111LLU,18428729675200069631LLU,7914754669233045503LLU,18410715276690585307LLU,18446583230865716991LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551612LLU,18446744073441116159LLU,18446744073575333887LLU,17582052945254416383LLU,18446744073709551615LLU,18446744073709551615LLU,18446673704965373951LLU,18446735277616529407LLU,18446744073709549823LLU,13180749371471298559LLU,18446744073709546349LLU,18446663652421852031LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744059750907919LLU,18446717686504226815LLU,18446735278153400319LLU,4611686018427387903LLU,18446744073642442752LLU,18446744073709551615LLU,13835339530258874367LLU,17870318505778216959LLU,17933333716189331455LLU,15797984123894628351LLU,18338662080430751158LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{17294948417469939711LLU,17294948262851117055LLU,18167450527938363391LLU,18376920687234244607LLU,18428747266580807679LLU,18442244871323385855LLU,9223368188564078591LLU,9223337947699331072LLU,17293820438530488383LLU,4611686018427387655LLU,18446744056530206718LLU,18158511566717190143LLU,18446462607322771905LLU,18446733883371095031LLU,63LLU},{18446744073709551615LLU,18446744072635809795LLU,18446735278153400319LLU,18446739675931475967LLU,1152921504606846975LLU,18446744073692774400LLU,18446744073709551615LLU,16141041801984212991LLU,18158531289743884287LLU,18437736874454812671LLU,18446744073709551615LLU,18410717475579633663LLU,13212435406529757183LLU,18446703863149887485LLU,63LLU},{18446744060824649727LLU,18446744022169944063LLU,18446708889337454591LLU,18446735277616525311LLU,18446744073508225023LLU,18446744073508225023LLU,18446743592673214463LLU,13835058053134680063LLU,17870283321271910399LLU,14411518807585587199LLU,18446744073709551615LLU,18302628885365260287LLU,15829589740253871679LLU,18446724105869721594LLU,63LLU},{18445829348754718719LLU,18445618448680615935LLU,18437877611940052991LLU,18444527458266398719LLU,18446729781132132351LLU,18446739676736782335LLU,10232182751432278015LLU,18446743257665765375LLU,2305842958210957248LLU,18446744073709551608LLU,18446744073709027329LLU,576460684657688575LLU,7851744467693342718LLU,18446744073703324687LLU,63LLU},{17568542146170191871LLU,17568542145563852799LLU,18284609814124297151LLU,18406209340563258303LLU,18433022168582275071LLU,18443313597418258431LLU,18446744072769798143LLU,17221745183285037027LLU,18293620449392720767LLU,18438860850216304495LLU,2305842994151948287LLU,18427602538271339007LLU,18446497302068592603LLU,11303973476865390591LLU,59LLU},{18446673722145243135LLU,18446462667452317695LLU,18442310842825326591LLU,18445635765988237311LLU,18446742974466359295LLU,18446742974466359295LLU,18302629435389509631LLU,9223371766271836159LLU,1152921487695413216LLU,4611686018427387900LLU,18446744073709486080LLU,288230342328844287LLU,18446744073575334399LLU,17867890509224115719LLU,54LLU},{18443366373988827135LLU,18443366373988237311LLU,18437736737011662815LLU,18444492205174292447LLU,18446691297151406079LLU,18446730879570006015LLU,9223372036854747135LLU,18410714177162182652LLU,18442240405361655743LLU,18446743833191383031LLU,16429131440643899391LLU,18446181055034556415LLU,18446744013580009469LLU,9217672166688947199LLU,61LLU},{18176528096013844479LLU,18176528095853412351LLU,18338654933823257983LLU,18419721101530627455LLU,18442521949055549439LLU,18445688542543544319LLU,18446744073590276095LLU,17726154938855192607LLU,18356671256507448575LLU,18445743518128275359LLU,18446744071595622399LLU,18435484249965461048LLU,18446709439093276647LLU,16950696755551260671LLU,63LLU},{18379190079295062015LLU,18379190079283265535LLU,18392700053522218815LLU,18433232862497996607LLU,18445688542546640895LLU,18446480190918639615LLU,18446744073707487231LLU,18230564694425337603LLU,18419722063622176383LLU,18446726756401414095LLU,2305843008949452799LLU,18443365961659580408LLU,18446739744382517235LLU,17987376776375953407LLU,27LLU},{17582039750913555711LLU,17582000167890964479LLU,18301498570433100797LLU,18410431594067000317LLU,18433233068656426959LLU,18443366167818010431LLU,18430981474074230776LLU,17289301308031879167LLU,18302064831840058359LLU,18438862773891891070LLU,18446251477467915263LLU,13816972179859567103LLU,10376047250842320863LLU,2233723842389852031LLU,46LLU},{8454757700450211157LLU,17678129737304986965LLU,18446744073709551615LLU,18446744073709551615LLU,18392700878181105663LLU,7908320945662590975LLU,13176245769082877659LLU,18446744073709542253LLU,18446741874686296063LLU,15811494920322472959LLU,18446744063892483510LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{17293822569908011008LLU,2305843005992468479LLU,18446735277482313728LLU,18446744073709551615LLU,18446744073709551615LLU,2639109381639110655LLU,10540996619990766153LLU,18446744073709537572LLU,18446744073709551615LLU,18383693678926364671LLU,7914754669233045503LLU,18410715276690585307LLU,18446583230865716991LLU,18446744073709551615LLU,63LLU},{18446532967208595456LLU,2305843009213693951LLU,2305843009212643336LLU,1152921504606320648LLU,18446740775157891840LLU,4503599627370495LLU,17437937756104819136LLU,18446743797762162687LLU,18446744056462839807LLU,18446744073709551615LLU,2662270765876903935LLU,18446744073709548105LLU,13212435405858668543LLU,18446703863149887485LLU,63LLU},{18446744073696964656LLU,11529215046018073359LLU,11529213883206074104LLU,1152920923175649016LLU,4611686018426601219LLU,2022116232688565260LLU,18446744073694871488LLU,18141906673793826815LLU,18408639398728716287LLU,18446620924119629823LLU,18442248187843444735LLU,18441980989320282055LLU,10649324268870959103LLU,17867889822031413244LLU,54LLU},{18446690472517694451LLU,13834843650514698047LLU,13832524743983955963LLU,4611052681475883003LLU,18446743236190928703LLU,18194541657058180348LLU,18320396993538555847LLU,18437173769880338431LLU,13833861776967327725LLU,18446744069950537725LLU,18442802461962870671LLU,8070300979338641407LLU,9207609438041309183LLU,18443366373987843804LLU,17LLU}};

uint_fast8_t X[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[26][15] = {{18446744073709551615LLU,17293822586282573811LLU,18158548881393057791LLU,18374695275496210431LLU,14987979559889010687LLU,18442240474149289983LLU,18446744073709551615LLU,4611545280939032575LLU,576443160117377024LLU,576460752303408896LLU,18446744056529682432LLU,144110790297772031LLU,18446703862864375168LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,63LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[26];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23] + cnt[24] + cnt[25];
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

    }
}

void printout(){
    sprintf(str, "[                          ,%5d]\n", this);
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
    fputs("[[0,1],[0,6],[0,7],[1,2],[1,6],[1,7],[1,8],[2,3],[2,7],[2,8],[2,9],[3,4],[3,8],[3,9],[3,10],[4,5],[4,9],[4,10],[4,11],[5,10],[5,11],[6,7],[7,8],[8,9],[9,10],[10,11]]\n", fout);
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
