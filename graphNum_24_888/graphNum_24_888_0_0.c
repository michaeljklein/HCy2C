#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_24_888_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 23;
static uint_fast32_t endhere = 0;
char str[34] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[24][11] = {{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,140737488355327LLU,0LLU,0LLU,18446744073642442752LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,2097151LLU,0LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{0LLU,0LLU,18446744073707454464LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{0LLU,18446744073709535232LLU,18446739675667234815LLU,18446321859113779199LLU,18446742424189140987LLU,18446744073709551615LLU,18446744073709551615LLU,67108863LLU,18446744073709551488LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,16383LLU,18446744073707454464LLU,18446744073709551615LLU,18374967954648334335LLU,14951246525134667775LLU,8466732080665984775LLU,18446744073706381151LLU,18442240474082181247LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,2097151LLU,18446744073701163008LLU,6341068275337658367LLU,18014383058295183229LLU,18442377498033772541LLU,3483333501212422655LLU,4503599627370443LLU,18446744073709551360LLU,65535LLU},{18446673979834695679LLU,18446741874686328735LLU,18446744073709551615LLU,8388607LLU,18446603336221196288LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744071562068095LLU,18446744073441116415LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,14910292466316869631LLU,17338857190986448639LLU,35167192217615LLU,0LLU,18446744073709551612LLU,18446744073709551615LLU,18445740398770272767LLU,18446742974331144191LLU,65535LLU},{9795329189530796033LLU,18392634907483439103LLU,18446744073709534207LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,3LLU,9727774095608643584LLU,14920425565478453247LLU,18442241573593808855LLU,65535LLU},{18446743936270598144LLU,18437738628667703295LLU,18446612132048920975LLU,18446269054499943397LLU,18446742216617164794LLU,18446744073709551615LLU,18446744073709551615LLU,18428729675267178495LLU,17298326168730075135LLU,17873276192056934375LLU,65535LLU},{137438953471LLU,18446744073709535232LLU,18446739675931475967LLU,13670676666869874687LLU,71978428999376799LLU,18446744073709486080LLU,18446744073705357567LLU,18014398446567420LLU,18446744073709551488LLU,576460718007428095LLU,65532LLU},{18446744073709551615LLU,2199023255551LLU,4398044413952LLU,18446744073701163008LLU,18375249429625044991LLU,15852657455549120511LLU,18442519475107397391LLU,18446744073707435007LLU,2147483647LLU,18446744073709551360LLU,65535LLU},{18446743936270630911LLU,18437806951132626943LLU,16140777918933493695LLU,17581736260034885615LLU,18446742835651672191LLU,65535LLU,18446744073709551612LLU,18428730774711697407LLU,17365316663428186111LLU,17874785855880814575LLU,65535LLU},{18446744073709551615LLU,2065875107839LLU,17870287719452639230LLU,18446735279764013055LLU,18438299790310636543LLU,18104254133656616959LLU,18175628369138286543LLU,18446744073709548303LLU,4503326643187839LLU,18238668095222710268LLU,65475LLU},{18158583997578592243LLU,18446744073709551615LLU,576460683825119233LLU,18446744073701163008LLU,225179981368524799LLU,16140892268339134463LLU,18443366369912144700LLU,17897297771889278975LLU,18442240748960088063LLU,9799832682052452099LLU,64575LLU},{288230376151711743LLU,9007096171577344LLU,17870419729567449086LLU,18446735309963001855LLU,18438299791994634175LLU,18446744073709486080LLU,18230008341638168527LLU,576460752303421247LLU,1152921233822576768LLU,9222773872462266364LLU,65472LLU},{13832876538262171611LLU,14082505346136407159LLU,542665334209904129LLU,18446744073709551104LLU,17569668046279147519LLU,15636497898701321023LLU,18446743591850931116LLU,13787749779529904383LLU,6228443323619606507LLU,16717361635605348346LLU,62270LLU},{18160761369904741367LLU,18446744073176875007LLU,18446744009266168319LLU,8796084634111LLU,1098878309078401016LLU,18442513152915013631LLU,284852673176391551LLU,17941773532815949820LLU,18442275658453749759LLU,11456946273857241351LLU,52479LLU},{18446744073172713217LLU,18445675341696401407LLU,16140848287810846703LLU,8358680899769597948LLU,18446744073701193848LLU,18446742974197989375LLU,18446673704969568255LLU,18446604427209998335LLU,18214242994138841087LLU,18415202967745683455LLU,47551LLU},{9195188668153724927LLU,17934458155764678640LLU,18444984706794415807LLU,18414901787136833135LLU,14968151902255054847LLU,1099511627520LLU,18446744073709551612LLU,9061383187757793279LLU,3746836550499941880LLU,17906311562629478319LLU,28659LLU},{18446744073176874767LLU,575392022703030287LLU,17872478221392412670LLU,18446735817138241535LLU,18439988674260613567LLU,18446742974264967423LLU,18446673709256163279LLU,18446612124261154815LLU,18217060234996740999LLU,18419708843707990012LLU,48076LLU},{18444567040643956735LLU,14987836623914269855LLU,542665334209904131LLU,18446744073709551104LLU,18446603336221196295LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446709110528802815LLU,16717361635336978431LLU,62270LLU},{9777314654656102655LLU,17953547137954349040LLU,18446744073709464575LLU,18446744073709551615LLU,14968276311519264767LLU,1099511627520LLU,70368744177660LLU,342413218179710976LLU,234187180623265784LLU,17901826110983765895LLU,28659LLU},{18194539195568946999LLU,4610832796931245055LLU,17906273583892660222LLU,36020540439330815LLU,4571153621781053432LLU,18446742982736941055LLU,18446674251462463327LLU,18158403739684175871LLU,18289399355569370015LLU,13817034497754861437LLU,40413LLU}};

static uint_fast64_t D[24][11] = {{8705528722479185918LLU,5681708744346455199LLU,13066354291934188546LLU,17252249280701702981LLU,18446722414469117938LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{9741215351230365697LLU,12765035329363096416LLU,18446744073709333501LLU,18446744073709551615LLU,12178014867386531839LLU,5644521464029866390LLU,6151802078816266502LLU,18446744073681018453LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,5380389781775581183LLU,1194494793007848634LLU,6268750865563453453LLU,12802222609679685225LLU,12294941994893285113LLU,18446744073670975914LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,5380389781777678335LLU,6547093318890249402LLU,18374787578636233583LLU,14068175646508515327LLU,3472501485617544963LLU,18446744073705849615LLU,18442240474082181247LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446739675665137663LLU,13093723333231378431LLU,6268929592055143577LLU,13685293488305837673LLU,17289172589941724925LLU,29064698LLU,18446744073709551488LLU,18446744073709551615LLU,65535LLU},{14987909279044620653LLU,18446741874686310281LLU,18446744073709551615LLU,18446744073709551615LLU,18302347410656985087LLU,8022423176478555607LLU,6151873067428576759LLU,18446744073700040533LLU,18446744071562068095LLU,18446744073441116415LLU,65535LLU},{13199980052020440723LLU,12765035329363114870LLU,18446744073709333501LLU,18446744073709551615LLU,216735732067205119LLU,15636481345846494012LLU,18442306509421462284LLU,3483333501193400575LLU,4503599627370443LLU,18446744073709551360LLU,65535LLU},{9359858538379182080LLU,16077781761905089983LLU,13681783276600531270LLU,17293099050567461845LLU,18446741253437192186LLU,18446744073709551615LLU,18446744073709551615LLU,9727774095675752447LLU,14920425565478453247LLU,18442241573593808855LLU,65535LLU},{9140999373630799871LLU,7996561889924804319LLU,14294863481650509499LLU,17298007421120689775LLU,18446619664445339655LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18445740398770272767LLU,18446742974331144191LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,7686237189037883391LLU,11282637125313191615LLU,21968757690255LLU,18446744073709486080LLU,4392698486542303235LLU,18446744073642964796LLU,18445097557525074175LLU,576460718007428095LLU,65532LLU},{18446744073709551615LLU,18437738628667703295LLU,16140764725052957071LLU,8935080055833096672LLU,18446743831305943934LLU,14068175646508515327LLU,17526547072780599295LLU,18446744073709521871LLU,17295469085287182207LLU,17873276192056934375LLU,65535LLU},{14987909279044620653LLU,18446744073709549449LLU,18446744073709551615LLU,13093723333231378431LLU,18230490202351180953LLU,4594744536903662787LLU,14974455553777941759LLU,14963410572517736432LLU,18446744073709551540LLU,18446744073441116415LLU,65535LLU},{9359858538379214847LLU,16077850084370013631LLU,4151893786206117750LLU,10372346190429147039LLU,18446728674037172223LLU,18446744073709551615LLU,4392698486542303235LLU,9727775195053684540LLU,14986773218931365631LLU,573468981093972959LLU,65532LLU},{18158513727618423793LLU,18446744073709551615LLU,18446744005233344511LLU,13093723335370473471LLU,71976505054977753LLU,4608308318640799743LLU,14987979555661136124LLU,17874215414972055548LLU,18446744073709551615LLU,9799832681811935743LLU,64575LLU},{14987979549004789103LLU,18446743940561401737LLU,18446744073709551615LLU,18446735277624918015LLU,18446744039350319551LLU,18378925164709493955LLU,18162951262059839487LLU,14986492929437073155LLU,18446744073455792180LLU,18238668095194791679LLU,65475LLU},{18446743966331182065LLU,18446743658964189183LLU,16140901064469635471LLU,8358126754532684256LLU,18446741909045542520LLU,572229831492698111LLU,14122162527236259836LLU,18432661768828882943LLU,18443886992466571263LLU,18080753933100998119LLU,64575LLU},{17293818439357364607LLU,18446744073172711421LLU,18446744073709551615LLU,8388607LLU,18446744073709551608LLU,18442257035476025331LLU,4437628926558207LLU,17292907719593820156LLU,18446744073709027390LLU,18320370605259423999LLU,53211LLU},{11529215020235745231LLU,14082505212992420867LLU,18412948659650953215LLU,18446744073709551615LLU,18443366339629791679LLU,17874786912510668815LLU,18446743528248459247LLU,11525810750299828227LLU,6228478232860032993LLU,18292772717345505278LLU,62438LLU},{252710927894315007LLU,17879288768263094256LLU,18444632789119540863LLU,18411277710845218335LLU,14968137740640583679LLU,18446744073709551360LLU,4392698486546497535LLU,360287970123052860LLU,1152683995398380792LLU,5761616845299774367LLU,28659LLU},{18302336415540707073LLU,16140887862435372479LLU,4152316072758345702LLU,1152914906455474172LLU,18446744073701165048LLU,18446744073709551615LLU,18446673704965373955LLU,18446744065186725887LLU,18429852104743581695LLU,13258580810288545791LLU,47548LLU},{18411224518077946879LLU,18446742012062334975LLU,18446744057603293215LLU,18410724072783544323LLU,14969824458250911743LLU,572229831559741439LLU,284852676431183868LLU,18216496683699671036LLU,18446466994900275199LLU,14624102781900812679LLU,28287LLU},{16658815013924894775LLU,13670368805627360252LLU,18446744073709333503LLU,18446744073709551615LLU,1093811759497609215LLU,18442240482621198320LLU,546497089375LLU,6988491441257316348LLU,12222769388683526046LLU,18320370605259489029LLU,53211LLU},{18230132586143088639LLU,5763903827066408095LLU,2194847614369762LLU,36020540439330812LLU,18446744073701163008LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18442517568158725119LLU,13258596759380168703LLU,47548LLU},{11527473290801022975LLU,18117943926106095603LLU,18446744070488325663LLU,18446744073709551107LLU,18445477436322742271LLU,4503599627370255LLU,18446744073709551612LLU,11512325516606570499LLU,6305008689879187449LLU,16857254879435948031LLU,30583LLU}};

uint_fast8_t X[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[24][11] = {{8705528722479185918LLU,5681708744346455199LLU,13066354291934188546LLU,17252249280701702981LLU,18446722414469117938LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,65535LLU}};

#if UINTPTR_MAX == 0xffffffffffffffff // 64-bit. Hopefully this means the cpu has 'popcnt'.
int counter (uint64_t * buf){
    uint64_t cnt[24];
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


    return cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] + cnt[7] + cnt[8] + cnt[9] + cnt[10] + cnt[11] + cnt[12] + cnt[13] + cnt[14] + cnt[15] + cnt[16] + cnt[17] + cnt[18] + cnt[19] + cnt[20] + cnt[21] + cnt[22] + cnt[23];
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

    }
}

void printout(){
    sprintf(str, "[                        ,%5d]\n", this);
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
    fputs("[[0,1],[0,2],[0,3],[1,4],[1,5],[2,5],[2,12],[3,6],[3,13],[4,6],[4,8],[5,7],[6,10],[7,8],[7,9],[8,11],[9,12],[9,14],[10,11],[10,13],[11,14],[12,15],[13,15],[14,15]]\n", fout);
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
