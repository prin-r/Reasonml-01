module Styles = {
  open Css;

  let overlay =
    style([
      display(`flex),
      position(`fixed),
      width(`percent(100.)),
      height(`percent(100.)),
      top(`zero),
      left(`zero),
      zIndex(10),
      backgroundColor(`rgba((0, 0, 0, 0.3))),
    ]);

  let card =
    style([
      display(`flex),
      width(`percent(100.)),
      height(`percent(80.)),
      padding2(~v=`px(20), ~h=`zero),
      justifyContent(`center),
      position(`absolute),
      opacity(0.),
      animation(
        ~duration=200,
        ~timingFunction=`cubicBezier((0.25, 0.46, 0.45, 0.94)),
        ~fillMode=`forwards,
        keyframes([
          (0, [transform(translateY(`px(1000))), opacity(0.)]),
          (100, [transform(translateY(`percent(40.))), opacity(1.)]),
        ]),
      ),
    ]);
};

[@react.component]
let make = () => {
  let (modal, dispatchModal) = React.useContext(ModalContext.context);

  switch (modal) {
  | None => React.null
  | Some(MessageModal(message)) =>
    <div className=Styles.overlay onClick={_ => dispatchModal(CloseModal)}>
      <div
        className=Styles.card
        onClick={e => ReactEvent.Mouse.stopPropagation(e)}>
        <MessageModal message />
      </div>
    </div>
  };
};