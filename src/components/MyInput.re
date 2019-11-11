open Css;

[@react.component]
let make = (~inputVal, ~setInputVal) => {
  <input
    className={style([
      height(`px(40)),
      padding(`px(10)),
      minWidth(`px(300)),
      borderRadius(`px(4)),
      fontSize(`px(18)),
      marginTop(`px(30)),
      outline(`zero, `none, black),
      border(`px(2), `solid, `rgb((145, 91, 179))),
    ])}
    value=inputVal
    onChange={event => setInputVal(ReactEvent.Form.target(event)##value)}
  />;
};