open Css;

[@react.component]
let make = (~message) => {
  let (_, dispatchModal) = React.useContext(ModalContext.context);
  <div
    className={style([
      width(`px(300)),
      height(`px(250)),
      flexDirection(`column),
      padding(`px(30)),
      alignItems(`center),
      fontSize(`px(14)),
      fontWeight(`bold),
      borderRadius(`px(8)),
      backgroundColor(white),
      boxShadow(
        Css.Shadow.box(
          ~x=`zero,
          ~y=`px(10),
          ~blur=`px(10),
          `rgba((0, 0, 0, 0.1)),
        ),
      ),
    ])}>
    <div
      className={style([
        fontSize(`px(20)),
        textAlign(center),
        lineHeight(`ch(2.5)),
      ])}>
      {message |> React.string}
    </div>
    <div
      className={style([
        display(`flex),
        minHeight(`px(40)),
        marginTop(`px(70)),
      ])}>
      <button
        onClick={_ => dispatchModal(CloseModal)}
        className={style([
          fontSize(`px(20)),
          color(white),
          border(`zero, `none, black),
          borderRadius(`px(4)),
          backgroundColor(`rgb((145, 91, 179))),
          marginLeft(`auto),
          marginRight(`auto),
          width(`px(100)),
          minHeight(`px(40)),
        ])}>
        {"close" |> React.string}
      </button>
    </div>
  </div>;
};