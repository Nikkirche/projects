// Generated from Input.g4 by ANTLR 4.13.1

package parser;

import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class InputLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, ARG=9, 
		HEAD=10, CODE=11, OP=12, IDENT_UP=13, REGEX=14, IDENT_LOW=15, WS=16;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "ARG", 
			"HEAD", "CODE", "OP", "IDENT_UP", "REGEX", "IDENT_LOW", "WS"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'from'", "':'", "'|'", "';'", "'['", "','", "']'", "'EPS'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, "ARG", "HEAD", 
			"CODE", "OP", "IDENT_UP", "REGEX", "IDENT_LOW", "WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public InputLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Input.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0010w\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001"+
		"\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001\b\u0001\b"+
		"\u0001\b\u0001\b\u0001\b\u0001\b\u0004\b=\b\b\u000b\b\f\b>\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0005\tJ\b"+
		"\t\n\t\f\tM\t\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001"+
		"\n\u0001\n\u0004\nW\b\n\u000b\n\f\nX\u0001\n\u0001\n\u0001\u000b\u0001"+
		"\u000b\u0001\f\u0004\f`\b\f\u000b\f\f\fa\u0001\r\u0001\r\u0004\rf\b\r"+
		"\u000b\r\f\rg\u0001\r\u0001\r\u0001\u000e\u0004\u000em\b\u000e\u000b\u000e"+
		"\f\u000en\u0001\u000f\u0004\u000fr\b\u000f\u000b\u000f\f\u000fs\u0001"+
		"\u000f\u0001\u000f\u0001K\u0000\u0010\u0001\u0001\u0003\u0002\u0005\u0003"+
		"\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015"+
		"\u000b\u0017\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010\u0001\u0000"+
		"\u0006\u0001\u0000}}\u0002\u0000*+??\u0001\u0000AZ\u0001\u0000\"\"\u0001"+
		"\u0000az\u0003\u0000\t\n\r\r  }\u0000\u0001\u0001\u0000\u0000\u0000\u0000"+
		"\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000"+
		"\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b"+
		"\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001"+
		"\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001"+
		"\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001"+
		"\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001"+
		"\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001"+
		"\u0000\u0000\u0000\u0001!\u0001\u0000\u0000\u0000\u0003&\u0001\u0000\u0000"+
		"\u0000\u0005(\u0001\u0000\u0000\u0000\u0007*\u0001\u0000\u0000\u0000\t"+
		",\u0001\u0000\u0000\u0000\u000b.\u0001\u0000\u0000\u0000\r0\u0001\u0000"+
		"\u0000\u0000\u000f2\u0001\u0000\u0000\u0000\u00116\u0001\u0000\u0000\u0000"+
		"\u0013B\u0001\u0000\u0000\u0000\u0015T\u0001\u0000\u0000\u0000\u0017\\"+
		"\u0001\u0000\u0000\u0000\u0019_\u0001\u0000\u0000\u0000\u001bc\u0001\u0000"+
		"\u0000\u0000\u001dl\u0001\u0000\u0000\u0000\u001fq\u0001\u0000\u0000\u0000"+
		"!\"\u0005f\u0000\u0000\"#\u0005r\u0000\u0000#$\u0005o\u0000\u0000$%\u0005"+
		"m\u0000\u0000%\u0002\u0001\u0000\u0000\u0000&\'\u0005:\u0000\u0000\'\u0004"+
		"\u0001\u0000\u0000\u0000()\u0005|\u0000\u0000)\u0006\u0001\u0000\u0000"+
		"\u0000*+\u0005;\u0000\u0000+\b\u0001\u0000\u0000\u0000,-\u0005[\u0000"+
		"\u0000-\n\u0001\u0000\u0000\u0000./\u0005,\u0000\u0000/\f\u0001\u0000"+
		"\u0000\u000001\u0005]\u0000\u00001\u000e\u0001\u0000\u0000\u000023\u0005"+
		"E\u0000\u000034\u0005P\u0000\u000045\u0005S\u0000\u00005\u0010\u0001\u0000"+
		"\u0000\u000067\u0005a\u0000\u000078\u0005r\u0000\u000089\u0005g\u0000"+
		"\u00009:\u0005{\u0000\u0000:<\u0001\u0000\u0000\u0000;=\b\u0000\u0000"+
		"\u0000<;\u0001\u0000\u0000\u0000=>\u0001\u0000\u0000\u0000><\u0001\u0000"+
		"\u0000\u0000>?\u0001\u0000\u0000\u0000?@\u0001\u0000\u0000\u0000@A\u0005"+
		"}\u0000\u0000A\u0012\u0001\u0000\u0000\u0000BC\u0005h\u0000\u0000CD\u0005"+
		"e\u0000\u0000DE\u0005a\u0000\u0000EF\u0005d\u0000\u0000FG\u0005|\u0000"+
		"\u0000GK\u0001\u0000\u0000\u0000HJ\t\u0000\u0000\u0000IH\u0001\u0000\u0000"+
		"\u0000JM\u0001\u0000\u0000\u0000KL\u0001\u0000\u0000\u0000KI\u0001\u0000"+
		"\u0000\u0000LN\u0001\u0000\u0000\u0000MK\u0001\u0000\u0000\u0000NO\u0005"+
		"|\u0000\u0000OP\u0005h\u0000\u0000PQ\u0005e\u0000\u0000QR\u0005a\u0000"+
		"\u0000RS\u0005d\u0000\u0000S\u0014\u0001\u0000\u0000\u0000TV\u0005{\u0000"+
		"\u0000UW\b\u0000\u0000\u0000VU\u0001\u0000\u0000\u0000WX\u0001\u0000\u0000"+
		"\u0000XV\u0001\u0000\u0000\u0000XY\u0001\u0000\u0000\u0000YZ\u0001\u0000"+
		"\u0000\u0000Z[\u0005}\u0000\u0000[\u0016\u0001\u0000\u0000\u0000\\]\u0007"+
		"\u0001\u0000\u0000]\u0018\u0001\u0000\u0000\u0000^`\u0007\u0002\u0000"+
		"\u0000_^\u0001\u0000\u0000\u0000`a\u0001\u0000\u0000\u0000a_\u0001\u0000"+
		"\u0000\u0000ab\u0001\u0000\u0000\u0000b\u001a\u0001\u0000\u0000\u0000"+
		"ce\u0005\"\u0000\u0000df\b\u0003\u0000\u0000ed\u0001\u0000\u0000\u0000"+
		"fg\u0001\u0000\u0000\u0000ge\u0001\u0000\u0000\u0000gh\u0001\u0000\u0000"+
		"\u0000hi\u0001\u0000\u0000\u0000ij\u0005\"\u0000\u0000j\u001c\u0001\u0000"+
		"\u0000\u0000km\u0007\u0004\u0000\u0000lk\u0001\u0000\u0000\u0000mn\u0001"+
		"\u0000\u0000\u0000nl\u0001\u0000\u0000\u0000no\u0001\u0000\u0000\u0000"+
		"o\u001e\u0001\u0000\u0000\u0000pr\u0007\u0005\u0000\u0000qp\u0001\u0000"+
		"\u0000\u0000rs\u0001\u0000\u0000\u0000sq\u0001\u0000\u0000\u0000st\u0001"+
		"\u0000\u0000\u0000tu\u0001\u0000\u0000\u0000uv\u0006\u000f\u0000\u0000"+
		"v \u0001\u0000\u0000\u0000\b\u0000>KXagns\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}