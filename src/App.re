module Styles = {
  open Css;

  let container =
    style([
      display(`flex),
      justifyContent(`center),
      width(`percent(100.)),
      height(`percent(100.)),
      position(`relative),
    ]);
};

[@react.component]
let make = () => {
  <ModalContext>
    <div className=Styles.container> <Dashboard /> </div>
    <Modal />
  </ModalContext>;
};