#include <stdio.h>
#include <stdint.h>
FILE * fout;
uint_fast32_t starthere = 0;
#define fopener fopen("graphNum_24_848_0_1_out.txt", "w")
uint_fast64_t y;
uint_fast32_t best = 1;
uint_fast32_t i;
uint_fast32_t this;
static uint_fast32_t maxpos = 23;
static uint_fast32_t endhere = 0;
char str[34] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static uint_fast64_t C[24][10] = {{0LLU,18446744039349813248LLU,18446744073709551615LLU,18446744073709551615LLU,18445758911190392831LLU,72057594037862399LLU,4611686018427322368LLU,18446726481523507200LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,1073741823LLU,0LLU,18428729675200069632LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18014398509481983LLU,0LLU,13835058055282163712LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{0LLU,0LLU,18446744072635809792LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,34359738367LLU,8608487747985866752LLU,18441954596763989341LLU,18194533112218516979LLU,18446744073709550567LLU,18446744073709551615LLU,17592186044415LLU,18446744073642442752LLU,72057594037927935LLU},{18410715276690587648LLU,9223372036854775807LLU,18446742978477162488LLU,18446741883276230655LLU,287808163653091327LLU,72057529613352956LLU,4611633241869254592LLU,18446744073692774400LLU,18446603336288305151LLU,72057594037927935LLU},{36028797018963967LLU,17904192775402815488LLU,18230571291595765887LLU,18446744073709551615LLU,18446177812268441359LLU,18446726481522982911LLU,18439988255408455743LLU,18446726481540284415LLU,140737488355327LLU,72057594037927920LLU},{18446744073642442752LLU,18446612130702557183LLU,14123288367006189567LLU,18158513568439333887LLU,14123081723214233854LLU,13898002883792601087LLU,4548635622704676863LLU,16138646996939439104LLU,18446744039382835071LLU,72057594037862415LLU},{67108863LLU,576460752269869024LLU,18446677072156819448LLU,18446610070713139199LLU,4539346949412749311LLU,4611685554570853916LLU,18446683050814209024LLU,18338657681578918911LLU,18446603370580934655LLU,72057593769558015LLU},{18446463569395445760LLU,9189463098254163967LLU,17582052945254385536LLU,12393906174149260092LLU,18446255632799494394LLU,18218995632833560575LLU,4547518458761314288LLU,15120835748894425072LLU,18446738782198158719LLU,72057525586882575LLU},{18446744071293636607LLU,18446744072097366047LLU,14753862683380940799LLU,18410855885329661951LLU,14114281232179072975LLU,14123192211278791167LLU,18446744073700885503LLU,18446108419623479311LLU,18442521914833174479LLU,72040070571298815LLU},{18446463569395445760LLU,17870283836802727935LLU,18446744073709518855LLU,18446744073642442751LLU,18445702617040671547LLU,18230571291595767807LLU,4549831421090283504LLU,17582035421785833456LLU,4503599627370495LLU,72057525586882560LLU},{4502738683189252032LLU,7378697636222062495LLU,18446744073709446758LLU,36028797018963967LLU,18445702617040671546LLU,12321848580485677055LLU,4302959488953461418LLU,18158512656948508526LLU,17298326100010598399LLU,71934444708953871LLU},{17284551109083263039LLU,17985575877445811191LLU,18014398241020319LLU,18446744073642426368LLU,18446744073709551615LLU,18302628884560084991LLU,18405366937996460021LLU,17870266828730105841LLU,1151795604699988031LLU,71072367194910960LLU},{11474745780757325304LLU,8608480547465062351LLU,18446744073172645751LLU,18446744073709551615LLU,18446744073709551615LLU,12285819784540454911LLU,4302959488953461418LLU,18158513216521371647LLU,18376865693397172223LLU,68652955338768335LLU},{8860220847649939271LLU,12297829404985220797LLU,18446744073709202090LLU,36028794871496703LLU,18445702617040671546LLU,18446744073709551615LLU,18446744073709551615LLU,18446742394990958156LLU,72057250440544255LLU,58441225932766271LLU},{18446741874686296057LLU,18446744073702211583LLU,18446744073709551615LLU,2147483647LLU,18428729675200069632LLU,18410715278838071295LLU,4611545280939032575LLU,18158513216521371647LLU,18376865693397172223LLU,68652955338768335LLU},{18446530768453759225LLU,18446744039879344127LLU,18014398509481983LLU,18446744073642426368LLU,18428729675200069633LLU,18410724071710130175LLU,4610982330985611263LLU,17582037071054110707LLU,18375812379511603263LLU,67835417042301888LLU},{18446744073709550845LLU,18410715818390192127LLU,14636698788954111LLU,16278260853055684592LLU,18446744072635809793LLU,18445624770839166975LLU,13834354299137687551LLU,17565157643423580155LLU,14754355329215101983LLU,52635797827820204LLU},{14411304411407643643LLU,18446744047935549951LLU,18445886235596554239LLU,18445028397483540495LLU,8628896887115612159LLU,18411839917131820991LLU,9223372036854775804LLU,18446734998375251895LLU,18392697028216865791LLU,33213187714185171LLU},{4575658320920050941LLU,18410856007734394848LLU,4611632417193590783LLU,16717254614409281520LLU,18446462597659164671LLU,18445758602024058492LLU,13835057987636427971LLU,18433228738385805307LLU,15987642337720270079LLU,52635797567832061LLU},{4575938693969739005LLU,18446744065652821984LLU,14754864626262867967LLU,18412859771041349619LLU,14987979558831984591LLU,14987321734088498812LLU,13835058055282150607LLU,18446737209397602427LLU,18442671450427883487LLU,52619327718760447LLU},{14379779340457537785LLU,18446744039878881763LLU,14757384488048656383LLU,18417899494256398323LLU,6323124244515327951LLU,18428072789460545213LLU,4611686018427387903LLU,18446728160242100659LLU,18443257494957457407LLU,67821450406346751LLU},{14379779340457537785LLU,18446744039878881763LLU,6148914690879127551LLU,18422724877128553813LLU,18429846191809052119LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18443257494890348547LLU,67821450406346751LLU}};

static uint_fast64_t D[24][10] = {{18446744073709551615LLU,18446744073709551615LLU,3689359586734637055LLU,136930970510094348LLU,18160751423028755696LLU,18429386562013477347LLU,14760956168727232511LLU,17592186044415LLU,18446744073642442752LLU,72057594037927935LLU},{10167551489326818702LLU,6148914679888585542LLU,18446744072636683605LLU,18446744073709551615LLU,12141704595390857215LLU,72057592963978054LLU,17520845960264482816LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{8279192584382732913LLU,12297829393820966073LLU,6148914691951471274LLU,18386696080109573461LLU,18444604864074455443LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,12297829382830948351LLU,60047993599978154LLU,6307178687953790572LLU,18374686480745573561LLU,14760956168727232511LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,17216957545155919871LLU,18365071619853873147LLU,6339975214624393071LLU,17357512769957565LLU,4611686018427322368LLU,18446726481523507200LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,17904192809762553855LLU,4337877936297212031LLU,6189768876999441615LLU,18433229135014854401LLU,18440944630736599523LLU,15988200400947380223LLU,7181165527702700031LLU,140737465838213LLU,72057594037927920LLU},{18446744073709551615LLU,9223372036854775807LLU,17582051846800801784LLU,12393903976786883388LLU,15749352745041150LLU,18435168348375351292LLU,17212691246630240255LLU,11265596138192895999LLU,18446603336243713402LLU,72057594037927935LLU},{36028797018963967LLU,9257289771514855392LLU,4611616749144506367LLU,15564301772626198479LLU,18370182863400271871LLU,18445476955240267267LLU,15996777141525937215LLU,9092450987255267327LLU,11069707146583046901LLU,72057593769558009LLU},{18446744073709551615LLU,18446603884365348863LLU,13849483647838552191LLU,8783848860249485567LLU,18437666780588474368LLU,18433098584246434303LLU,18375108691071074303LLU,14119275145273016319LLU,7377177664558255887LLU,72057594037862406LLU},{36028794670153727LLU,18446744073709027328LLU,18212557992346255359LLU,18410717474639708159LLU,18433233274290569167LLU,18446717754149306371LLU,15996785876407009343LLU,9222421990105672703LLU,18442381211570307013LLU,72040070313082879LLU},{18446463569395449855LLU,140737454800895LLU,4611686018427387776LLU,9799832789026078476LLU,18374404730874036219LLU,18442944161410711551LLU,18445618174876450800LLU,17298326168728059903LLU,11069842592661238015LLU,72057525576794105LLU},{18446744071360741375LLU,18446744073709551615LLU,18428729676006424575LLU,18410715277210222591LLU,2251799008346111LLU,18446735279763881984LLU,14771801829957763071LLU,4502491319649692671LLU,18446608627754876864LLU,72040070313082879LLU},{17284815092805664767LLU,18446744073709419511LLU,537919487LLU,18446744073709535232LLU,2251799008346111LLU,18446744072635809792LLU,14987975161827819519LLU,18373701317253132287LLU,18445564146603769856LLU,71065422129774591LLU},{4502755201432145919LLU,7493989676865277855LLU,18446744073709453310LLU,519634943LLU,18446744073709551614LLU,12393897380578066431LLU,17942321673989581487LLU,4575534066289341295LLU,18446662586234322943LLU,71923934500290559LLU},{18156226638205910911LLU,13527612338777063165LLU,1073462203LLU,18446744071562067968LLU,18446744073709551615LLU,18446744073709551615LLU,14987975161827819519LLU,18373700198107401949LLU,1152903495540539388LLU,58403708286008575LLU},{14960816399817766399LLU,18446744051160576999LLU,18446744072636858367LLU,18446744073709551615LLU,2251799008346111LLU,18410715276690587648LLU,18446744073709551615LLU,18446744073709551615LLU,18443257494890348547LLU,67821450406346751LLU},{16849030147752148751LLU,11068046471193246324LLU,18446744073173309849LLU,18446744073709551615LLU,12141704595390857215LLU,6196953087261594438LLU,14370662840368321877LLU,18373700198107401949LLU,1152903495540539388LLU,58403708286008575LLU},{4067023133868494799LLU,576460236789845532LLU,18446744073441673208LLU,18446744072081702911LLU,12141704595390857215LLU,288230376151634758LLU,13907054626408022031LLU,4502491290199376463LLU,18446717163189305340LLU,58437737294921727LLU},{13871085752856088543LLU,576460752202756127LLU,18445886235506933752LLU,18445028395856166911LLU,3530822107858468863LLU,3746993631546763151LLU,13907054626424746812LLU,4503599619736732559LLU,18446739708009512956LLU,26950198219571199LLU},{4607455097675841519LLU,18410715311033487356LLU,18443366373810765823LLU,16278260853122334719LLU,17257793772083740671LLU,14987977360865729398LLU,18446744004990127311LLU,18428747241207365247LLU,14771217433100156895LLU,49501107575054015LLU},{18446744073709031391LLU,18446744073642438687LLU,18445688529593303167LLU,9221260946746110207LLU,17428860464057548798LLU,17568540492407235055LLU,13836183955180352511LLU,1152288178393055119LLU,8610601010492002284LLU,26950198227887447LLU},{18446743944860532703LLU,36028796918300671LLU,18446744073709027328LLU,2305843007074594831LLU,18230500923925331962LLU,18429855574603595759LLU,13835058124001640444LLU,18014398509432831LLU,3692950801027679228LLU,26951183384311123LLU},{18446735277616529359LLU,34242297855LLU,18446744073709027328LLU,144115185928437759LLU,18194542494576803834LLU,18446744073709550567LLU,13835058055282229247LLU,17592186044415LLU,72057250440544252LLU,58441225932766271LLU},{18446735277616529359LLU,18446744073592111103LLU,18446744073709551615LLU,72057591890477055LLU,18446706544276404094LLU,36028797018963967LLU,13835058055282163712LLU,18446742394990958156LLU,72057250440544255LLU,58441225932766271LLU}};

uint_fast8_t X[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint_fast64_t A[24][10] = {{18446744073709551615LLU,18446744073709551615LLU,3689359586734637055LLU,136930970510094348LLU,18160751423028755696LLU,18429386562013477347LLU,14760956168727232511LLU,17592186044415LLU,18446744073642442752LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU},{18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,18446744073709551615LLU,72057594037927935LLU}};

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
    fputs("[[0,1],[0,8],[0,15],[1,2],[1,14],[2,3],[2,5],[3,4],[3,11],[4,5],[4,12],[5,6],[6,7],[6,9],[7,8],[7,15],[8,9],[9,10],[10,11],[10,13],[11,12],[12,13],[13,14],[14,15]]\n", fout);
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

