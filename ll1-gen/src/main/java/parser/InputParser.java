// Generated from Input.g4 by ANTLR 4.13.1

package parser;

import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class InputParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, ARG=9, 
		HEAD=10, CODE=11, OP=12, IDENT_UP=13, REGEX=14, IDENT_LOW=15, WS=16;
	public static final int
		RULE_gramm = 0, RULE_head = 1, RULE_rule = 2, RULE_noterminal_rule = 3, 
		RULE_rule_inn = 4, RULE_code = 5, RULE_rdec = 6, RULE_redecl = 7, RULE_indecl = 8, 
		RULE_ruleb = 9, RULE_rule_body = 10, RULE_inh = 11, RULE_terminal_rule = 12, 
		RULE_terminal_rule_inn = 13, RULE_terminal = 14, RULE_noterminal = 15, 
		RULE_ident = 16, RULE_epsilon = 17;
	private static String[] makeRuleNames() {
		return new String[] {
			"gramm", "head", "rule", "noterminal_rule", "rule_inn", "code", "rdec", 
			"redecl", "indecl", "ruleb", "rule_body", "inh", "terminal_rule", "terminal_rule_inn", 
			"terminal", "noterminal", "ident", "epsilon"
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

	@Override
	public String getGrammarFileName() { return "Input.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public InputParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class GrammContext extends ParserRuleContext {
		public HeadContext head() {
			return getRuleContext(HeadContext.class,0);
		}
		public List<RuleContext> rule_() {
			return getRuleContexts(RuleContext.class);
		}
		public RuleContext rule_(int i) {
			return getRuleContext(RuleContext.class,i);
		}
		public GrammContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_gramm; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterGramm(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitGramm(this);
		}
	}

	public final GrammContext gramm() throws RecognitionException {
		GrammContext _localctx = new GrammContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_gramm);
		int _la;
		try {
			setState(47);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case HEAD:
				enterOuterAlt(_localctx, 1);
				{
				setState(36);
				head();
				setState(38); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(37);
					rule_();
					}
					}
					setState(40); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 40994L) != 0) );
				}
				break;
			case T__0:
			case T__4:
			case IDENT_UP:
			case IDENT_LOW:
				enterOuterAlt(_localctx, 2);
				{
				setState(43); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(42);
					rule_();
					}
					}
					setState(45); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & 40994L) != 0) );
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class HeadContext extends ParserRuleContext {
		public TerminalNode HEAD() { return getToken(InputParser.HEAD, 0); }
		public HeadContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_head; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterHead(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitHead(this);
		}
	}

	public final HeadContext head() throws RecognitionException {
		HeadContext _localctx = new HeadContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_head);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(49);
			match(HEAD);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RuleContext extends ParserRuleContext {
		public Terminal_ruleContext terminal_rule() {
			return getRuleContext(Terminal_ruleContext.class,0);
		}
		public Noterminal_ruleContext noterminal_rule() {
			return getRuleContext(Noterminal_ruleContext.class,0);
		}
		public RuleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterRule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitRule(this);
		}
	}

	public final RuleContext rule_() throws RecognitionException {
		RuleContext _localctx = new RuleContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_rule);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(53);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT_UP:
				{
				setState(51);
				terminal_rule();
				}
				break;
			case T__0:
			case T__4:
			case IDENT_LOW:
				{
				setState(52);
				noterminal_rule();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Noterminal_ruleContext extends ParserRuleContext {
		public RdecContext rdec() {
			return getRuleContext(RdecContext.class,0);
		}
		public RedeclContext redecl() {
			return getRuleContext(RedeclContext.class,0);
		}
		public IndeclContext indecl() {
			return getRuleContext(IndeclContext.class,0);
		}
		public Noterminal_ruleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_noterminal_rule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterNoterminal_rule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitNoterminal_rule(this);
		}
	}

	public final Noterminal_ruleContext noterminal_rule() throws RecognitionException {
		Noterminal_ruleContext _localctx = new Noterminal_ruleContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_noterminal_rule);
		try {
			setState(61);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT_LOW:
				enterOuterAlt(_localctx, 1);
				{
				setState(55);
				rdec();
				}
				break;
			case T__0:
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				setState(56);
				redecl();
				setState(57);
				match(T__0);
				setState(58);
				indecl();
				setState(59);
				rdec();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rule_innContext extends ParserRuleContext {
		public RulebContext ruleb() {
			return getRuleContext(RulebContext.class,0);
		}
		public CodeContext code() {
			return getRuleContext(CodeContext.class,0);
		}
		public Rule_innContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rule_inn; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterRule_inn(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitRule_inn(this);
		}
	}

	public final Rule_innContext rule_inn() throws RecognitionException {
		Rule_innContext _localctx = new Rule_innContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_rule_inn);
		try {
			setState(67);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(63);
				ruleb();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(64);
				ruleb();
				setState(65);
				code();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class CodeContext extends ParserRuleContext {
		public TerminalNode CODE() { return getToken(InputParser.CODE, 0); }
		public CodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_code; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterCode(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitCode(this);
		}
	}

	public final CodeContext code() throws RecognitionException {
		CodeContext _localctx = new CodeContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_code);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			match(CODE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RdecContext extends ParserRuleContext {
		public NoterminalContext noterminal() {
			return getRuleContext(NoterminalContext.class,0);
		}
		public List<Rule_innContext> rule_inn() {
			return getRuleContexts(Rule_innContext.class);
		}
		public Rule_innContext rule_inn(int i) {
			return getRuleContext(Rule_innContext.class,i);
		}
		public RdecContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rdec; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterRdec(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitRdec(this);
		}
	}

	public final RdecContext rdec() throws RecognitionException {
		RdecContext _localctx = new RdecContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_rdec);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(71);
			noterminal();
			setState(72);
			match(T__1);
			setState(73);
			rule_inn();
			setState(78);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2) {
				{
				{
				setState(74);
				match(T__2);
				setState(75);
				rule_inn();
				}
				}
				setState(80);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(81);
			match(T__3);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RedeclContext extends ParserRuleContext {
		public List<IdentContext> ident() {
			return getRuleContexts(IdentContext.class);
		}
		public IdentContext ident(int i) {
			return getRuleContext(IdentContext.class,i);
		}
		public RedeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_redecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterRedecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitRedecl(this);
		}
	}

	public final RedeclContext redecl() throws RecognitionException {
		RedeclContext _localctx = new RedeclContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_redecl);
		int _la;
		try {
			setState(95);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				setState(84);
				match(T__4);
				setState(91);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==IDENT_UP || _la==IDENT_LOW) {
					{
					{
					setState(85);
					ident();
					setState(86);
					match(T__5);
					setState(87);
					ident();
					}
					}
					setState(93);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(94);
				match(T__6);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IndeclContext extends ParserRuleContext {
		public List<IdentContext> ident() {
			return getRuleContexts(IdentContext.class);
		}
		public IdentContext ident(int i) {
			return getRuleContext(IdentContext.class,i);
		}
		public IndeclContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_indecl; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterIndecl(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitIndecl(this);
		}
	}

	public final IndeclContext indecl() throws RecognitionException {
		IndeclContext _localctx = new IndeclContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_indecl);
		int _la;
		try {
			setState(109);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT_LOW:
				enterOuterAlt(_localctx, 1);
				{
				}
				break;
			case T__4:
				enterOuterAlt(_localctx, 2);
				{
				setState(98);
				match(T__4);
				setState(105);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==IDENT_UP || _la==IDENT_LOW) {
					{
					{
					setState(99);
					ident();
					setState(100);
					match(T__5);
					setState(101);
					ident();
					}
					}
					setState(107);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(108);
				match(T__6);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RulebContext extends ParserRuleContext {
		public Rule_bodyContext rule_body() {
			return getRuleContext(Rule_bodyContext.class,0);
		}
		public EpsilonContext epsilon() {
			return getRuleContext(EpsilonContext.class,0);
		}
		public RulebContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ruleb; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterRuleb(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitRuleb(this);
		}
	}

	public final RulebContext ruleb() throws RecognitionException {
		RulebContext _localctx = new RulebContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_ruleb);
		try {
			setState(113);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IDENT_UP:
			case IDENT_LOW:
				enterOuterAlt(_localctx, 1);
				{
				setState(111);
				rule_body();
				}
				break;
			case T__7:
				enterOuterAlt(_localctx, 2);
				{
				setState(112);
				epsilon();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Rule_bodyContext extends ParserRuleContext {
		public List<TerminalContext> terminal() {
			return getRuleContexts(TerminalContext.class);
		}
		public TerminalContext terminal(int i) {
			return getRuleContext(TerminalContext.class,i);
		}
		public List<InhContext> inh() {
			return getRuleContexts(InhContext.class);
		}
		public InhContext inh(int i) {
			return getRuleContext(InhContext.class,i);
		}
		public List<NoterminalContext> noterminal() {
			return getRuleContexts(NoterminalContext.class);
		}
		public NoterminalContext noterminal(int i) {
			return getRuleContext(NoterminalContext.class,i);
		}
		public Rule_bodyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rule_body; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterRule_body(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitRule_body(this);
		}
	}

	public final Rule_bodyContext rule_body() throws RecognitionException {
		Rule_bodyContext _localctx = new Rule_bodyContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_rule_body);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(118); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(118);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
				case 1:
					{
					setState(115);
					terminal();
					}
					break;
				case 2:
					{
					setState(116);
					inh();
					}
					break;
				case 3:
					{
					setState(117);
					noterminal();
					}
					break;
				}
				}
				setState(120); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==IDENT_UP || _la==IDENT_LOW );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class InhContext extends ParserRuleContext {
		public TerminalNode IDENT_LOW() { return getToken(InputParser.IDENT_LOW, 0); }
		public TerminalNode ARG() { return getToken(InputParser.ARG, 0); }
		public InhContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_inh; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterInh(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitInh(this);
		}
	}

	public final InhContext inh() throws RecognitionException {
		InhContext _localctx = new InhContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_inh);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(122);
			match(IDENT_LOW);
			setState(123);
			match(ARG);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Terminal_ruleContext extends ParserRuleContext {
		public TerminalContext terminal() {
			return getRuleContext(TerminalContext.class,0);
		}
		public Terminal_rule_innContext terminal_rule_inn() {
			return getRuleContext(Terminal_rule_innContext.class,0);
		}
		public Terminal_ruleContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_terminal_rule; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterTerminal_rule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitTerminal_rule(this);
		}
	}

	public final Terminal_ruleContext terminal_rule() throws RecognitionException {
		Terminal_ruleContext _localctx = new Terminal_ruleContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_terminal_rule);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(125);
			terminal();
			setState(126);
			match(T__1);
			setState(127);
			terminal_rule_inn();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Terminal_rule_innContext extends ParserRuleContext {
		public TerminalNode REGEX() { return getToken(InputParser.REGEX, 0); }
		public Terminal_rule_innContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_terminal_rule_inn; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterTerminal_rule_inn(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitTerminal_rule_inn(this);
		}
	}

	public final Terminal_rule_innContext terminal_rule_inn() throws RecognitionException {
		Terminal_rule_innContext _localctx = new Terminal_rule_innContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_terminal_rule_inn);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(129);
			match(REGEX);
			setState(130);
			match(T__3);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TerminalContext extends ParserRuleContext {
		public TerminalNode IDENT_UP() { return getToken(InputParser.IDENT_UP, 0); }
		public TerminalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_terminal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterTerminal(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitTerminal(this);
		}
	}

	public final TerminalContext terminal() throws RecognitionException {
		TerminalContext _localctx = new TerminalContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_terminal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(132);
			match(IDENT_UP);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NoterminalContext extends ParserRuleContext {
		public TerminalNode IDENT_LOW() { return getToken(InputParser.IDENT_LOW, 0); }
		public NoterminalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_noterminal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterNoterminal(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitNoterminal(this);
		}
	}

	public final NoterminalContext noterminal() throws RecognitionException {
		NoterminalContext _localctx = new NoterminalContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_noterminal);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(134);
			match(IDENT_LOW);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IdentContext extends ParserRuleContext {
		public List<TerminalNode> IDENT_LOW() { return getTokens(InputParser.IDENT_LOW); }
		public TerminalNode IDENT_LOW(int i) {
			return getToken(InputParser.IDENT_LOW, i);
		}
		public List<TerminalNode> IDENT_UP() { return getTokens(InputParser.IDENT_UP); }
		public TerminalNode IDENT_UP(int i) {
			return getToken(InputParser.IDENT_UP, i);
		}
		public IdentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ident; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterIdent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitIdent(this);
		}
	}

	public final IdentContext ident() throws RecognitionException {
		IdentContext _localctx = new IdentContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_ident);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(137); 
			_errHandler.sync(this);
			_alt = 1;
			do {
				switch (_alt) {
				case 1:
					{
					{
					setState(136);
					_la = _input.LA(1);
					if ( !(_la==IDENT_UP || _la==IDENT_LOW) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				setState(139); 
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class EpsilonContext extends ParserRuleContext {
		public EpsilonContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_epsilon; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).enterEpsilon(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof InputListener ) ((InputListener)listener).exitEpsilon(this);
		}
	}

	public final EpsilonContext epsilon() throws RecognitionException {
		EpsilonContext _localctx = new EpsilonContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_epsilon);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(141);
			match(T__7);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\u0004\u0001\u0010\u0090\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001"+
		"\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004"+
		"\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007"+
		"\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b"+
		"\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007"+
		"\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0001\u0000\u0001"+
		"\u0000\u0004\u0000\'\b\u0000\u000b\u0000\f\u0000(\u0001\u0000\u0004\u0000"+
		",\b\u0000\u000b\u0000\f\u0000-\u0003\u00000\b\u0000\u0001\u0001\u0001"+
		"\u0001\u0001\u0002\u0001\u0002\u0003\u00026\b\u0002\u0001\u0003\u0001"+
		"\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u0003>\b"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003\u0004D\b"+
		"\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0005\u0006M\b\u0006\n\u0006\f\u0006P\t\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\u0007\u0001\u0007\u0001"+
		"\u0007\u0001\u0007\u0005\u0007Z\b\u0007\n\u0007\f\u0007]\t\u0007\u0001"+
		"\u0007\u0003\u0007`\b\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0005\bh\b\b\n\b\f\bk\t\b\u0001\b\u0003\bn\b\b\u0001\t\u0001\t\u0003"+
		"\tr\b\t\u0001\n\u0001\n\u0001\n\u0004\nw\b\n\u000b\n\f\nx\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\f\u0001\f\u0001\r\u0001"+
		"\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u0010"+
		"\u0004\u0010\u008a\b\u0010\u000b\u0010\f\u0010\u008b\u0001\u0011\u0001"+
		"\u0011\u0001\u0011\u0000\u0000\u0012\u0000\u0002\u0004\u0006\b\n\f\u000e"+
		"\u0010\u0012\u0014\u0016\u0018\u001a\u001c\u001e \"\u0000\u0001\u0002"+
		"\u0000\r\r\u000f\u000f\u008d\u0000/\u0001\u0000\u0000\u0000\u00021\u0001"+
		"\u0000\u0000\u0000\u00045\u0001\u0000\u0000\u0000\u0006=\u0001\u0000\u0000"+
		"\u0000\bC\u0001\u0000\u0000\u0000\nE\u0001\u0000\u0000\u0000\fG\u0001"+
		"\u0000\u0000\u0000\u000e_\u0001\u0000\u0000\u0000\u0010m\u0001\u0000\u0000"+
		"\u0000\u0012q\u0001\u0000\u0000\u0000\u0014v\u0001\u0000\u0000\u0000\u0016"+
		"z\u0001\u0000\u0000\u0000\u0018}\u0001\u0000\u0000\u0000\u001a\u0081\u0001"+
		"\u0000\u0000\u0000\u001c\u0084\u0001\u0000\u0000\u0000\u001e\u0086\u0001"+
		"\u0000\u0000\u0000 \u0089\u0001\u0000\u0000\u0000\"\u008d\u0001\u0000"+
		"\u0000\u0000$&\u0003\u0002\u0001\u0000%\'\u0003\u0004\u0002\u0000&%\u0001"+
		"\u0000\u0000\u0000\'(\u0001\u0000\u0000\u0000(&\u0001\u0000\u0000\u0000"+
		"()\u0001\u0000\u0000\u0000)0\u0001\u0000\u0000\u0000*,\u0003\u0004\u0002"+
		"\u0000+*\u0001\u0000\u0000\u0000,-\u0001\u0000\u0000\u0000-+\u0001\u0000"+
		"\u0000\u0000-.\u0001\u0000\u0000\u0000.0\u0001\u0000\u0000\u0000/$\u0001"+
		"\u0000\u0000\u0000/+\u0001\u0000\u0000\u00000\u0001\u0001\u0000\u0000"+
		"\u000012\u0005\n\u0000\u00002\u0003\u0001\u0000\u0000\u000036\u0003\u0018"+
		"\f\u000046\u0003\u0006\u0003\u000053\u0001\u0000\u0000\u000054\u0001\u0000"+
		"\u0000\u00006\u0005\u0001\u0000\u0000\u00007>\u0003\f\u0006\u000089\u0003"+
		"\u000e\u0007\u00009:\u0005\u0001\u0000\u0000:;\u0003\u0010\b\u0000;<\u0003"+
		"\f\u0006\u0000<>\u0001\u0000\u0000\u0000=7\u0001\u0000\u0000\u0000=8\u0001"+
		"\u0000\u0000\u0000>\u0007\u0001\u0000\u0000\u0000?D\u0003\u0012\t\u0000"+
		"@A\u0003\u0012\t\u0000AB\u0003\n\u0005\u0000BD\u0001\u0000\u0000\u0000"+
		"C?\u0001\u0000\u0000\u0000C@\u0001\u0000\u0000\u0000D\t\u0001\u0000\u0000"+
		"\u0000EF\u0005\u000b\u0000\u0000F\u000b\u0001\u0000\u0000\u0000GH\u0003"+
		"\u001e\u000f\u0000HI\u0005\u0002\u0000\u0000IN\u0003\b\u0004\u0000JK\u0005"+
		"\u0003\u0000\u0000KM\u0003\b\u0004\u0000LJ\u0001\u0000\u0000\u0000MP\u0001"+
		"\u0000\u0000\u0000NL\u0001\u0000\u0000\u0000NO\u0001\u0000\u0000\u0000"+
		"OQ\u0001\u0000\u0000\u0000PN\u0001\u0000\u0000\u0000QR\u0005\u0004\u0000"+
		"\u0000R\r\u0001\u0000\u0000\u0000S`\u0001\u0000\u0000\u0000T[\u0005\u0005"+
		"\u0000\u0000UV\u0003 \u0010\u0000VW\u0005\u0006\u0000\u0000WX\u0003 \u0010"+
		"\u0000XZ\u0001\u0000\u0000\u0000YU\u0001\u0000\u0000\u0000Z]\u0001\u0000"+
		"\u0000\u0000[Y\u0001\u0000\u0000\u0000[\\\u0001\u0000\u0000\u0000\\^\u0001"+
		"\u0000\u0000\u0000][\u0001\u0000\u0000\u0000^`\u0005\u0007\u0000\u0000"+
		"_S\u0001\u0000\u0000\u0000_T\u0001\u0000\u0000\u0000`\u000f\u0001\u0000"+
		"\u0000\u0000an\u0001\u0000\u0000\u0000bi\u0005\u0005\u0000\u0000cd\u0003"+
		" \u0010\u0000de\u0005\u0006\u0000\u0000ef\u0003 \u0010\u0000fh\u0001\u0000"+
		"\u0000\u0000gc\u0001\u0000\u0000\u0000hk\u0001\u0000\u0000\u0000ig\u0001"+
		"\u0000\u0000\u0000ij\u0001\u0000\u0000\u0000jl\u0001\u0000\u0000\u0000"+
		"ki\u0001\u0000\u0000\u0000ln\u0005\u0007\u0000\u0000ma\u0001\u0000\u0000"+
		"\u0000mb\u0001\u0000\u0000\u0000n\u0011\u0001\u0000\u0000\u0000or\u0003"+
		"\u0014\n\u0000pr\u0003\"\u0011\u0000qo\u0001\u0000\u0000\u0000qp\u0001"+
		"\u0000\u0000\u0000r\u0013\u0001\u0000\u0000\u0000sw\u0003\u001c\u000e"+
		"\u0000tw\u0003\u0016\u000b\u0000uw\u0003\u001e\u000f\u0000vs\u0001\u0000"+
		"\u0000\u0000vt\u0001\u0000\u0000\u0000vu\u0001\u0000\u0000\u0000wx\u0001"+
		"\u0000\u0000\u0000xv\u0001\u0000\u0000\u0000xy\u0001\u0000\u0000\u0000"+
		"y\u0015\u0001\u0000\u0000\u0000z{\u0005\u000f\u0000\u0000{|\u0005\t\u0000"+
		"\u0000|\u0017\u0001\u0000\u0000\u0000}~\u0003\u001c\u000e\u0000~\u007f"+
		"\u0005\u0002\u0000\u0000\u007f\u0080\u0003\u001a\r\u0000\u0080\u0019\u0001"+
		"\u0000\u0000\u0000\u0081\u0082\u0005\u000e\u0000\u0000\u0082\u0083\u0005"+
		"\u0004\u0000\u0000\u0083\u001b\u0001\u0000\u0000\u0000\u0084\u0085\u0005"+
		"\r\u0000\u0000\u0085\u001d\u0001\u0000\u0000\u0000\u0086\u0087\u0005\u000f"+
		"\u0000\u0000\u0087\u001f\u0001\u0000\u0000\u0000\u0088\u008a\u0007\u0000"+
		"\u0000\u0000\u0089\u0088\u0001\u0000\u0000\u0000\u008a\u008b\u0001\u0000"+
		"\u0000\u0000\u008b\u0089\u0001\u0000\u0000\u0000\u008b\u008c\u0001\u0000"+
		"\u0000\u0000\u008c!\u0001\u0000\u0000\u0000\u008d\u008e\u0005\b\u0000"+
		"\u0000\u008e#\u0001\u0000\u0000\u0000\u000f(-/5=CN[_imqvx\u008b";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}