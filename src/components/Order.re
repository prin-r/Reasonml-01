open Css;

[@react.component]
let make = (~title, ~close) => {
  <div
    className={style([
      display(`flex),
      alignItems(center),
      paddingLeft(`px(10)),
      paddingRight(`px(10)),
      marginTop(`px(20)),
      minHeight(`px(40)),
      borderRadius(`px(30)),
      backgroundColor(white),
      boxShadow(
        Css.Shadow.box(
          ~x=`zero,
          ~y=`px(3),
          ~blur=`px(10),
          `rgba((0, 0, 0, 0.1)),
        ),
      ),
    ])}>
    {title |> React.string}
    <button
      className={style([
        marginLeft(`auto),
        textAlign(center),
        color(`rgb((145, 91, 179))),
        height(`px(20)),
        width(`px(20)),
        border(`px(1), `solid, `rgb((145, 91, 179))),
        borderRadius(`percent(50.)),
      ])}
      onClick={_ => close(title)}>
      <div
        className={style([
          position(`relative),
          top(`percent(50.)),
          left(`px(-1)),
        ])}>
        {"x" |> React.string}
      </div>
    </button>
  </div>;
};